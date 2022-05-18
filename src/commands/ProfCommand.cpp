//
// Created by xhy on 2022/5/17.
//
#include "CommandHelper.h"
#include "DynamicCommandAPI.h"

namespace tr {
    void SetupProfCommand() {
        using ParamType = DynamicCommand::ParameterType;
        // create a dynamic command
        auto command = DynamicCommand::createCommand("prof", "profile world health",
                                                     CommandPermissionLevel::GameMasters);

        auto &optContinue = command->setEnum("continue", {"continue"});
        command->mandatory("prof", ParamType::Enum, optContinue, CommandParameterOption::EnumAutocompleteExpansion);
        command->mandatory("NumberOfTick", ParamType::Int);
        command->addOverload({optContinue, "NumberOfTick"});

        auto &optOther = command->setEnum("other", {"chunk", "pt", "actor"});
        command->mandatory("prof", ParamType::Enum, optOther, CommandParameterOption::EnumAutocompleteExpansion);
        command->addOverload({optOther});

        auto cb = [](DynamicCommand const &command, CommandOrigin const &origin, CommandOutput &output,
                     std::unordered_map<std::string, DynamicCommand::Result> &results) {};
        command->setCallback(cb);

        DynamicCommand::setup(std::move(command));
    }

}