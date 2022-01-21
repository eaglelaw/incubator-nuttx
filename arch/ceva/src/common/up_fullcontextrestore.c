/****************************************************************************
 * arch/ceva/src/common/up_fullcontextrestore.c
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include "svcall.h"
#include "up_internal.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: up_fullcontextrestore
 *
 * Description:
 *   Restore the current thread context.  Full prototype is:
 *
 *   void up_fullcontextrestore(uint32_t *restoreregs) noreturn_function;
 *
 * Return:
 *   None
 *
 ****************************************************************************/

void up_fullcontextrestore(uint32_t *restoreregs)
{
  /* Let sys_call1() do all of the work */

  sys_call1(SYS_restore_context, (uintptr_t)restoreregs);
  while (1); /* Shut up the compiler warning */
}