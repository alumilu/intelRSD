/*!
 * @copyright
 * Copyright (c) 2015-2016 Intel Corporation
 *
 * @copyright
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * @copyright
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * @copyright
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file requests/network/delete_ethernet_switch_port.cpp
 *
 * @brief Network request DeleteEthernetSwitchPort implementation
 * */

#include "agent-framework/module-ref/requests/network/delete_ethernet_switch_port.hpp"
#include "agent-framework/module-ref/constants/network.hpp"
#include "agent-framework/module-ref/constants/common.hpp"
#include <json/json.h>

using namespace agent_framework::model::requests;
using namespace agent_framework::model::literals;

DeleteEthernetSwitchPort::DeleteEthernetSwitchPort(const std::string& port,
            agent_framework::model::attribute::Oem):
                m_port(port),
                m_oem{} {}

Json::Value DeleteEthernetSwitchPort::to_json() const {
    Json::Value value;
    value[SwitchPort::PORT] = m_port;
    value[SwitchPort::OEM] = m_oem.to_json();
    return value;
}

DeleteEthernetSwitchPort DeleteEthernetSwitchPort::from_json(const Json::Value& json) {
    return DeleteEthernetSwitchPort{
        json[SwitchPort::PORT].asString(),
        agent_framework::model::attribute::Oem::from_json(
            json[SwitchPort::OEM])
    };
}
