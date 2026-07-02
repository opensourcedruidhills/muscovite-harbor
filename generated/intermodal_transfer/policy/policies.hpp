#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <cstdint>
#include <string>
#include <string_view>
#include <type_traits>

// Forward-declared policy infrastructure interfaces.
// @warning: These structs are ABSTRACT INTERFACES. Inject concrete implementations via PolicyRegistry constructor.
struct EventPublisher {
    virtual ~EventPublisher() = default;
    template<typename Event>
    auto publish(const Event& event) -> bool {
        static_assert(sizeof(Event) == 0,
            "Provide a concrete EventPublisher — the default stub always fails.");
        (void)event;
        return false;
    }
};

/// @warning: Abstract interface — inject concrete implementation.
struct CommandDispatcher {
    virtual ~CommandDispatcher() = default;
    template<typename Command>
    auto dispatch(const Command& command) -> bool {
        static_assert(sizeof(Command) == 0,
            "Provide a concrete CommandDispatcher — the default stub always fails.");
        (void)command;
        return false;
    }
};

/// @warning: Abstract interface — inject concrete implementation.
struct NotificationSender {
    virtual ~NotificationSender() = default;
    struct Notification { std::string_view type; std::string_view payload; };
    template<typename Notification>
    auto send(const Notification& notification) -> bool {
        static_assert(sizeof(Notification) == 0,
            "Provide a concrete NotificationSender — the default stub always fails.");
        (void)notification;
        return false;
    }
};

/// @warning: Abstract interface — inject concrete implementation.
struct ServiceCaller {
    virtual ~ServiceCaller() = default;
    template<typename Event>
    auto call(std::string_view service_name, const Event& event) -> bool {
        static_assert(sizeof(Event) == 0,
            "Provide a concrete ServiceCaller — the default stub always fails.");
        (void)service_name;
        (void)event;
        return false;
    }
};

namespace intermodal_transfer {

/// Result of a policy execution.
enum class PolicyResult {
    Success,
    ConditionNotMet,
    ActionFailed,
    Timeout,
    MaxRetriesExceeded,
};

/// Configuration for policy execution behavior.
struct PolicyOptions {
    std::int32_t max_retries{0};
    std::int32_t timeout_seconds{0};
    std::int32_t priority{0};
    bool async{false};
};

/// Log departure confirmations
/// Trigger type: DOMAIN_EVENT
/// Triggered by: DepartureConfirmed
class LogDeparturePolicyHandler {
public:
    explicit LogDeparturePolicyHandler(
        EventPublisher* publisher = nullptr,
        CommandDispatcher* command_dispatcher = nullptr,
        NotificationSender* notifier = nullptr,
        ServiceCaller* service_caller = nullptr)
        : publisher_{publisher}
        , command_dispatcher_{command_dispatcher}
        , notifier_{notifier}
        , service_caller_{service_caller} {}

    [[nodiscard]] auto matches(const DepartureConfirmed& event) const -> bool;
    [[nodiscard]] auto execute(const DepartureConfirmed& event) const -> PolicyResult;
    [[nodiscard]] auto name() const -> std::string { return "LogDeparture"; }

    [[nodiscard]] auto options() const -> PolicyOptions {
        return PolicyOptions{
            .max_retries = 0,
            .timeout_seconds = 0,
            .priority = 0,
            .async = false,
        };
    }

private:
    EventPublisher* publisher_{nullptr};
    CommandDispatcher* command_dispatcher_{nullptr};
    NotificationSender* notifier_{nullptr};
    ServiceCaller* service_caller_{nullptr};
};

} // namespace intermodal_transfer
