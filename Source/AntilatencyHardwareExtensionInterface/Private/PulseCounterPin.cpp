// Copyright 2021, ALT LLC. All Rights Reserved.
// This file is part of Antilatency SDK.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://www.antilatency.com/eula
// You may not use this file except in compliance with the License.
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "PulseCounterPin.h"

#include "HardwareExtensionInterfaceLog.h"

#include <ExceptionCheck.h>

Antilatency::InterfaceContract::ExceptionCode UPulseCounterPin::GetValue(uint16& result) {
	if (!IsValid()) {
	    HARDWAREEXTENSIONINTERFACE_LOG(Warning, TEXT("Calling object wrapper method while native object is null"));
		return Antilatency::InterfaceContract::ExceptionCode::ErrorPointer;
	}

    uint16_t nativeResult;
	auto exception = _native.getValue(nativeResult);
	ANTILATENCY_EXCEPTION_CHECK_RETURN_ON_FAIL();

    result = static_cast<uint16>(nativeResult);

	return exception;
}

bool UPulseCounterPin::IsValid() const {
    if (_native == nullptr) {
        return false;
    }

    return true;
}