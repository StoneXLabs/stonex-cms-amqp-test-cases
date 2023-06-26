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

#include <Cases/proton-cpp-client-session-tests.h>

#include <Configuration/TestSuiteConfiguration.h>
#include <Wrapper/CMSClientTestUnit.h>
#include <algorithm>

/// <summary>
/// Test if session is created without exception
/// Exceptions are tracked by user implemented exception listener
/// </summary>
/// <returns></returns>
TEST_CASE_STATUS test_create_session(CMSClientTestUnit* uut, TestCasePerformer *tcp, TestCaseVerifier* tcv)
{


	return TEST_CASE_STATUS::FINISHED;

}

TEST_CASE_STATUS test_close_session(CMSClientTestUnit* uut, TestCasePerformer *tcp, TestCaseVerifier* tcv)
{
	
		try
		{
			uut->closeSessions();
		}
		catch (const ::cms::CMSException& ex)
		{
//			if (verifier)
//				verifier->onException(ex);
//			else
				std::cout << ex.what() << std::endl;
		}
	

	return TEST_CASE_STATUS::FINISHED;
}

