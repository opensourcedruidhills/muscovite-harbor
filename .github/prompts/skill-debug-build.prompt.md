# Skill: Debug Build Failures

Use this skill when encountering Conan, CMake, C++ compilation, linker, or
Docker build failures.

## Conan Failures

### "Package not found"

```bash
# Check available remotes
conan remote list

# Verify muscovite package exists
conan search "muscovite/*" -r=muscovite

# Re-install dependencies
conan install --profile conan_profiles/debug . --build=missing
```

### Version conflict

```bash
# Check what's installed
conan list "muscovite/*"

# Force specific version
# Edit conanfile.py: self.requires("muscovite/2.25.0")
conan install --profile conan_profiles/debug .
```

### muscomp not found after conan install

muscomp is a `tool_requires` dependency. Ensure your conanfile.py has:

```python
def build_requirements(self):
    self.tool_requires("muscomp/[>=2.25.0]")
```

After `conan install`, muscomp is available in the Conan-managed build environment.
Run it via `conan run` or activate the environment first.

## CMake Failures

### "Could not find muscovite"

```bash
# Ensure Conan generated the toolchain
ls build/debug/generators/muscoviteConfig.cmake

# Re-run conan install
conan install --profile conan_profiles/debug .

# Re-configure
cmake --preset debug
```

### "Target not found"

Check that `generated/src/CMakeLists.txt` exists and references valid targets.
Regenerate if needed:

```bash
muscomp --project project.mus --cmake --output generated/
cmake --preset debug
```

## C++ Compilation Failures

### Unknown type in generated code

This usually means a DSL type isn't in the type registry. Check:

1. `doc/TYPE-MAPPINGS.md` — is the type listed?
2. The `.ddd` file — is the type spelled correctly?
3. Run `muscomp --lint-only` to catch type errors before generation

### Missing include

Generated code includes headers from the muscovite framework. Ensure:

```bash
# Conan dependencies are installed
conan install --profile conan_profiles/debug .

# CMake can find the package
cmake --preset debug 2>&1 | grep muscovite
```

### C++23 features not available

Muscovite requires C++23. Check your compiler:

```bash
g++ --version   # Need GCC 13+ (preferably 15)
clang --version # Need Clang 17+ (preferably 19)
```

Ensure CMakeLists.txt has:

```cmake
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
```

## Linker Failures

### Undefined symbols from muscovite

```bash
# Check that all required components are linked
grep "find_package(muscovite" generated/src/CMakeLists.txt

# Should include all needed components:
# find_package(muscovite CONFIG REQUIRED COMPONENTS dba server grpc)
```

### Multiple definition errors

Usually caused by shared/static library mismatch. Ensure Conan options match:

```python
default_options = {
    "shared": True,
    "grpc/*:shared": True,
    "protobuf/*:shared": True,
}
```

## Docker Build Failures

### Image pull failures

```bash
# Check network
docker pull postgres:16-alpine

# Use local registry if behind firewall
# Edit docker-compose.yml image references
```

### Volume permission issues

```bash
# Check volume ownership
docker compose exec postgres ls -la /var/lib/postgresql/data

# Fix permissions
docker compose down -v
docker compose up -d
```

## General Debugging Strategy

1. **Read the error message carefully** — muscomp and CMake give specific diagnostics
2. **Lint first**: `muscomp --project project.mus --lint-only`
3. **Check types**: `doc/TYPE-MAPPINGS.md`
4. **Check syntax**: Read the PEG grammar for the construct you're using
5. **Regenerate**: `muscomp --project project.mus --full --output generated/`
6. **Rebuild clean**: `cmake --preset debug && cmake --build --preset debug`
7. **Check Conan**: `conan install --profile conan_profiles/debug . --build=missing`
