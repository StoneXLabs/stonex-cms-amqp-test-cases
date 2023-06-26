/*
 * Copyright 2022 StoneX Financial Ltd.
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <Cases/proton-cpp-client-connection-tests.h>

#include <chrono>
#include <thread>
#include <numeric>
#include <algorithm>




#include <Configuration/TestSuiteConfiguration.h>
#include <Wrapper/CMSClientTestUnit.h>



/// <summary>
/// Test if connection to broker is created without exception
/// Exceptions are tracked by user implemented exception listener
/// </summary>
/// <returns></returns>
TEST_CASE_STATUS test_create_connection(CMSClientTestUnit* uut, TestCasePerformer *tcp, TestCaseVerifier* tcv)
{


	return TEST_CASE_STATUS::FINISHED;
}

/// <summary>
/// Test if connection to broker can be stopped and started without exception
/// Exceptions are tracked by user implemented exception listener
/// </summary>
/// <returns></returns>
TEST_CASE_STATUS test_stop_and_restart_connection(CMSClientTestUnit* uut, TestCasePerformer *tcp, TestCaseVerifier* tcv)
{


	

	try {

			uut->closeConnections();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			uut->startConnections();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	catch (const ::cms::CMSException& ex)
	{

	}

	return TEST_CASE_STATUS::FINISHED;

}


