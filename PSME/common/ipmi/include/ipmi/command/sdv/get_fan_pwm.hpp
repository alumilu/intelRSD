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
 *
 * @file get_fan_pwm.hpp
 * */

#ifndef IPMI_COMMAND_SDV_GET_FAN_PWM_HPP
#define IPMI_COMMAND_SDV_GET_FAN_PWM_HPP

#include "ipmi/request.hpp"
#include "ipmi/response.hpp"

#include <cstdint>
#include <vector>
#include <map>
#include <string>
#include <iostream>

using std::uint8_t;
using std::uint32_t;
using std::vector;
using std::map;
using std::string;

namespace ipmi {
namespace command {
namespace sdv {

namespace request {

/*!
 * @brief Request message for Get Fan PWM command.
 */
class GetFanPwm: public Request {
public:

    /*!
     * @brief Default constructor.
     */
    GetFanPwm();

    /*! Copy constructor. */
    GetFanPwm(const GetFanPwm&) = default;

    /*! Assignment operator */
    GetFanPwm& operator=(const GetFanPwm&) = default;

    /*!
     * @brief Default destructor.
     */
    virtual ~GetFanPwm();

    virtual void pack(vector<uint8_t>& data) const;

};

}

namespace response {

/*!
 * @brief Response message for Get Fan PWM command.
 */
class GetFanPwm: public Response {
public:

    /*!
     * @brief Default constructor.
     */
    GetFanPwm();

    /*! Copy constructor. */
    GetFanPwm(const GetFanPwm&) = default;

    /*! Assignment operator */
    GetFanPwm& operator=(const GetFanPwm&) = default;

    /*!
     * @brief Default destructor.
     */
    virtual ~GetFanPwm();

    /*!
     * @brief Gets sensor reading.
     * @return Sensor reading.
     */
    uint8_t get_sensor_reading() const;

    virtual void unpack(const vector<uint8_t>& data);

    uint8_t get_maximum_pwm() const {
        return m_maximum_pwm;
    }

private:

    static constexpr size_t RESPONSE_SIZE = 4;

    static constexpr size_t OFFSET_MAXIMUM_PWM = 2;

    uint8_t m_maximum_pwm{};
};
}

}
}
}
#endif

