/*
 * Copyright (c) 2015 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.intel.podm.allocation.validation;

import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.Spliterator;
import java.util.function.Consumer;

import static java.lang.String.format;

public class Violations implements Iterable<String> {
    Set<String> violations = new LinkedHashSet<>();

    public static Violations createWithViolations(String... violations) {
        Violations combinedViolations = new Violations();

        for (String violation : violations) {
            combinedViolations.addViolation(violation);
        }

        return combinedViolations;
    }

    public Violations addViolation(String violation) {
        violations.add(violation);
        return this;
    }

    public void addMissingPropertyViolation(String propertyName) {
        violations.add(format("Mandatory property %s is missing", propertyName));
    }

    @Override
    public Iterator<String> iterator() {
        return violations.iterator();
    }

    @Override
    public void forEach(Consumer<? super String> consumer) {
        violations.forEach(consumer);
    }

    @Override
    public Spliterator<String> spliterator() {
        return violations.spliterator();
    }

    public boolean hasViolations() {
        return !violations.isEmpty();
    }

    public String[] toStringArray() {
        return violations.toArray(new String[violations.size()]);
    }

    public Violations addAll(Violations violations) {
        violations.forEach(this.violations::add);
        return this;
    }
}
