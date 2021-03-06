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
 * @file lvm_clone_task.hpp
 * @brief Lvm clone task
 * */

#ifndef PSME_AGENT_STORAGE_LVM_LVM_CLONE_TASK_HPP
#define PSME_AGENT_STORAGE_LVM_LVM_CLONE_TASK_HPP

#include "lvm_create_data.hpp"

namespace agent {
namespace storage {
namespace lvm {

/*! @brief Class supports copy lvm from source to destination */
class LvmCloneTask {
public:
    /*!
     * @brief Constructor
     * @param[in] create_data Data to clone
     * */
    explicit LvmCloneTask(const LvmCreateData& create_data);

    /*! @brief Starts cloning */
    void operator()();
private:
    LvmCreateData m_create_data{};

    std::string get_source() const;
    std::string get_dest() const;
};

}
}
}
#endif	/* PSME_AGENT_STORAGE_LVM_VOLUME_GROUP_HPP */

