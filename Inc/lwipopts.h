
/**
  ******************************************************************************
  * File Name          : lwipopts.h
  * Description        : This file overrides LwIP stack default configuration
  *                      done in opt.h file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
 
/* Define to prevent recursive inclusion --------------------------------------*/
#ifndef __LWIPOPTS__H__
#define __LWIPOPTS__H__

#include "main.h"

/*-----------------------------------------------------------------------------*/
/* Current version of LwIP supported by CubeMx: 2.0.3 -*/
/*-----------------------------------------------------------------------------*/

/* Within 'USER CODE' section, code will be kept by default at each generation */
/* USER CODE BEGIN 0 */


#define LWIP_PLATFORM_DIAG(x) do {printf x;} while(0)

#if 1
#define LWIP_DEBUG 0
#define LWIP_STATS 0
#define LWIP_DBG_TRACE


#define LWIP_DBG_TYPES_ON 0x78U
//#define UDP_DEBUG LWIP_DBG_ON	// trace udp

#include <stdio.h>
#include <stdlib.h>




/* USER CODE END 0 */

#ifdef __cplusplus
 extern "C" {
#endif

/* STM32CubeMX Specific Parameters (not defined in opt.h) ---------------------*/
/* Parameters set in STM32CubeMX LwIP Configuration GUI -*/
/*----- WITH_RTOS enabled (Since FREERTOS is set) -----*/
#define WITH_RTOS 1
/*----- WITH_MBEDTLS enabled (Since MBEDTLS and FREERTOS are set) -----*/
#define WITH_MBEDTLS 1
/*----- CHECKSUM_BY_HARDWARE enabled -----*/
#define CHECKSUM_BY_HARDWARE 1
/*-----------------------------------------------------------------------------*/

/* LwIP Stack Parameters (modified compared to initialization value in opt.h) -*/
/* Parameters set in STM32CubeMX LwIP Configuration GUI -*/
/*----- Value in opt.h for LWIP_DHCP: 0 -----*/
#define LWIP_DHCP 1
/*----- Value in opt.h for LWIP_DNS: 0 -----*/
#define LWIP_DNS 1
/*----- Default Value for MEMP_NUM_TCP_PCB: 5 ---*/
#define MEMP_NUM_TCP_PCB 32
/*----- Default Value for LWIP_TCPIP_CORE_LOCKING: 0 ---*/
#define LWIP_TCPIP_CORE_LOCKING 1
/*----- Value in opt.h for MEM_ALIGNMENT: 1 -----*/
#define MEM_ALIGNMENT 4
/*----- Default Value for MEM_SIZE: 1600 ---*/
#define MEM_SIZE 12000
/*----- Default Value for MEMP_OVERFLOW_CHECK: 0 ---*/
#define MEMP_OVERFLOW_CHECK 2
/*----- Default Value for MEMP_SANITY_CHECK: 0 ---*/
#define MEMP_SANITY_CHECK 1
/*----- Default Value for LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT: 0 ---*/
#define LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT 1
/*----- Default Value for MEMP_NUM_TCP_PCB_LISTEN: 8 ---*/
#define MEMP_NUM_TCP_PCB_LISTEN 16
/*----- Default Value for PBUF_POOL_SIZE: 16 ---*/
#define PBUF_POOL_SIZE 32
/*----- Default Value for ARP_TABLE_SIZE: 10 ---*/
#define ARP_TABLE_SIZE 32
/*----- Default Value for ARP_QUEUEING: 0 ---*/
#define ARP_QUEUEING 1
/*----- Default Value for ARP_QUEUE_LEN: 3 ---*/
#define ARP_QUEUE_LEN 32
/*----- Value in opt.h for LWIP_ETHERNET: LWIP_ARP || PPPOE_SUPPORT -*/
#define LWIP_ETHERNET 1
/*----- Default Value for LWIP_RAW: 0 ---*/
#define LWIP_RAW 1
/*----- Value in opt.h for LWIP_DNS_SECURE: (LWIP_DNS_SECURE_RAND_XID | LWIP_DNS_SECURE_NO_MULTIPLE_OUTSTANDING | LWIP_DNS_SECURE_RAND_SRC_PORT) -*/
#define LWIP_DNS_SECURE 7
/*----- Value in opt.h for TCP_SND_QUEUELEN: (4*TCP_SND_BUF + (TCP_MSS - 1))/TCP_MSS -----*/
#define TCP_SND_QUEUELEN 9
/*----- Value in opt.h for TCP_SNDLOWAT: LWIP_MIN(LWIP_MAX(((TCP_SND_BUF)/2), (2 * TCP_MSS) + 1), (TCP_SND_BUF) - 1) -*/
#define TCP_SNDLOWAT 1071
/*----- Value in opt.h for TCP_SNDQUEUELOWAT: LWIP_MAX(TCP_SND_QUEUELEN)/2, 5) -*/
#define TCP_SNDQUEUELOWAT 5
/*----- Value in opt.h for TCP_WND_UPDATE_THRESHOLD: LWIP_MIN(TCP_WND/4, TCP_MSS*4) -----*/
#define TCP_WND_UPDATE_THRESHOLD 536
/*----- Default Value for LWIP_NETIF_STATUS_CALLBACK: 0 ---*/
#define LWIP_NETIF_STATUS_CALLBACK 1
/*----- Default Value for LWIP_NETIF_LINK_CALLBACK: 0 ---*/
#define LWIP_NETIF_LINK_CALLBACK 1
/*----- Value in opt.h for TCPIP_THREAD_STACKSIZE: 0 -----*/
#define TCPIP_THREAD_STACKSIZE 1024
/*----- Value in opt.h for TCPIP_THREAD_PRIO: 1 -----*/
#define TCPIP_THREAD_PRIO 3
/*----- Value in opt.h for TCPIP_MBOX_SIZE: 0 -----*/
#define TCPIP_MBOX_SIZE 6
/*----- Value in opt.h for SLIPIF_THREAD_STACKSIZE: 0 -----*/
#define SLIPIF_THREAD_STACKSIZE 1024
/*----- Value in opt.h for SLIPIF_THREAD_PRIO: 1 -----*/
#define SLIPIF_THREAD_PRIO 3
/*----- Value in opt.h for DEFAULT_THREAD_STACKSIZE: 0 -----*/
#define DEFAULT_THREAD_STACKSIZE 1024
/*----- Value in opt.h for DEFAULT_THREAD_PRIO: 1 -----*/
#define DEFAULT_THREAD_PRIO 3
/*----- Value in opt.h for DEFAULT_UDP_RECVMBOX_SIZE: 0 -----*/
#define DEFAULT_UDP_RECVMBOX_SIZE 6
/*----- Value in opt.h for DEFAULT_TCP_RECVMBOX_SIZE: 0 -----*/
#define DEFAULT_TCP_RECVMBOX_SIZE 6
/*----- Value in opt.h for DEFAULT_ACCEPTMBOX_SIZE: 0 -----*/
#define DEFAULT_ACCEPTMBOX_SIZE 6
/*----- Value in opt.h for RECV_BUFSIZE_DEFAULT: INT_MAX -----*/
#define RECV_BUFSIZE_DEFAULT 20000
/*----- Value in opt.h for LWIP_USE_EXTERNAL_MBEDTLS: 0 -----*/
#define LWIP_USE_EXTERNAL_MBEDTLS 1
/*----- Default Value for LWIP_HTTPD: 0 ---*/
#define LWIP_HTTPD 1
/*----- Default Value for LWIP_HTTPD_CGI_SSI: 0 ---*/
#define LWIP_HTTPD_CGI_SSI 1
/*----- Default Value for LWIP_HTTPD_SSI: 0 ---*/
#define LWIP_HTTPD_SSI 1
/*----- Default Value for LWIP_HTTPD_SUPPORT_POST: 0 ---*/
#define LWIP_HTTPD_SUPPORT_POST 1
/*----- Default Value for LWIP_HTTPD_SUPPORT_EXTSTATUS: 0 ---*/
#define LWIP_HTTPD_SUPPORT_EXTSTATUS 1
/*----- Default Value for LWIP_HTTPD_SUPPORT_11_KEEPALIVE: 0 ---*/
#define LWIP_HTTPD_SUPPORT_11_KEEPALIVE 1
/*----- Default Value for LWIP_HTTPD_SSI_INCLUDE_TAG: 1 ---*/
#define LWIP_HTTPD_SSI_INCLUDE_TAG 0
/*----- Default Value for LWIP_HTTPD_ABORT_ON_CLOSE_MEM_ERROR: 0 ---*/
#define LWIP_HTTPD_ABORT_ON_CLOSE_MEM_ERROR 1
/*----- Value in opt.h for HTTPD_USE_CUSTOM_FSDATA: 0 -----*/
#define HTTPD_USE_CUSTOM_FSDATA 1
/*----- Default Value for LWIP_STATS: 0 ---*/
#define LWIP_STATS 1
/*----- Value in opt.h for MIB2_STATS: 0 or SNMP_LWIP_MIB2 -----*/
#define MIB2_STATS 0
/*----- Value in opt.h for CHECKSUM_GEN_IP: 1 -----*/
#define CHECKSUM_GEN_IP 0
/*----- Value in opt.h for CHECKSUM_GEN_UDP: 1 -----*/
#define CHECKSUM_GEN_UDP 0
/*----- Value in opt.h for CHECKSUM_GEN_TCP: 1 -----*/
#define CHECKSUM_GEN_TCP 0
/*----- Value in opt.h for CHECKSUM_GEN_ICMP: 1 -----*/
#define CHECKSUM_GEN_ICMP 0
/*----- Value in opt.h for CHECKSUM_GEN_ICMP6: 1 -----*/
#define CHECKSUM_GEN_ICMP6 0
/*----- Value in opt.h for CHECKSUM_CHECK_IP: 1 -----*/
#define CHECKSUM_CHECK_IP 0
/*----- Value in opt.h for CHECKSUM_CHECK_UDP: 1 -----*/
#define CHECKSUM_CHECK_UDP 0
/*----- Value in opt.h for CHECKSUM_CHECK_TCP: 1 -----*/
#define CHECKSUM_CHECK_TCP 0
/*----- Value in opt.h for CHECKSUM_CHECK_ICMP: 1 -----*/
#define CHECKSUM_CHECK_ICMP 0
/*----- Value in opt.h for CHECKSUM_CHECK_ICMP6: 1 -----*/
#define CHECKSUM_CHECK_ICMP6 0
/*----- Default Value for LWIP_DBG_MIN_LEVEL: LWIP_DBG_LEVEL_ALL ---*/
#define LWIP_DBG_MIN_LEVEL LWIP_DBG_LEVEL_WARNING
/*----- Default Value for LWIP_DBG_TYPES_ON: LWIP_DBG_ON ---*/
#define LWIP_DBG_TYPES_ON LWIP_DBG_OFF
/*-----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */
#define MEMP_SANITY_CHECK 1

#define LINK_STATS                      0
#define ETHARP_STATS                    0
#define IP_STATS                        0
#define IPFRAG_STATS                    0
#define ICMP_STATS                      0
#define IGMP_STATS                      0
#define UDP_STATS                       0
#define TCP_STATS                       0
#define MEM_STATS                       0
#define MEMP_STATS                      0
#define SYS_STATS                       0
#define LWIP_STATS_DISPLAY              0
#define IP6_STATS                       0
#define ICMP6_STATS                     0
#define IP6_FRAG_STATS                  0
#define MLD6_STATS                      0
#define ND6_STATS                       0
#define MIB2_STATS                      0
#endif
/* USER CODE END 1 */

#ifdef __cplusplus
}
#endif
#endif /*__LWIPOPTS__H__ */

/************************* (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
