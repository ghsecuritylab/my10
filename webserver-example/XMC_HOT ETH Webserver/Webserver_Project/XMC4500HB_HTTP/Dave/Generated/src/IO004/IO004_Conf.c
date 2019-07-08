/*CODE_BLOCK_BEGIN[IO004_Conf.c]*/
/*******************************************************************************
 Copyright (c) 2011, Infineon Technologies AG                                 **
 All rights reserved.                                                         **
                                                                              **
 Redistribution and use in source and binary forms, with or without           **
 modification,are permitted provided that the following conditions are met:   **
                                                                              **
 *Redistributions of source code must retain the above copyright notice,      **
 this list of conditions and the following disclaimer.                        **
 *Redistributions in binary form must reproduce the above copyright notice,   **
 this list of conditions and the following disclaimer in the documentation    **
 and/or other materials provided with the distribution.                       **
 *Neither the name of the copyright holders nor the names of its contributors **
 may be used to endorse or promote products derived from this software without** 
 specific prior written permission.                                           **
                                                                              **
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  **
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **
 ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **
 LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **
 SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **
 CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **
 POSSIBILITY OF SUCH DAMAGE.                                                  **
                                                                              **
 To improve the quality of the software, users are encouraged to share        **
 modifications, enhancements or bug fixes with Infineon Technologies AG       **
 dave@infineon.com).                                                          **
                                                                              **
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC4XXX Series/XMC1XXX Series                          **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : App Developer                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Dec 3, 2012                                           **
**                                                                            **
**                                                                            **
*******************************************************************************/
/**
 * @file   IO004_Conf.c
 * 
 * @App Version IO004 <1.0.12>
 *
 * @brief  Configuration file generated for App.
 *
 */

/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/
#include <DAVE3.h>

   


const IO004_HandleType IO004_Handle1 = {
  .PortNr   = 5U , /* Mapped Port */
  .PortPin  = 11U,   /* Mapped Pin */
  .PortRegs = (IO004_PORTS_TypeDef*)PORT5_BASE /* Port Base Address*/		
};
   


const IO004_HandleType IO004_Handle2 = {
  .PortNr   = 3U , /* Mapped Port */
  .PortPin  = 9U,   /* Mapped Pin */
  .PortRegs = (IO004_PORTS_TypeDef*)PORT3_BASE /* Port Base Address*/		
};

/*CODE_BLOCK_END*/

