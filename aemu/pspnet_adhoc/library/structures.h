/*
 * This file is part of PRO ONLINE.

 * PRO ONLINE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * PRO ONLINE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PRO ONLINE. If not, see <http://www.gnu.org/licenses/ .
 */

#ifndef _ADHOC_STRUCTURES_H_
#define _ADHOC_STRUCTURES_H_

// Ethernet Address
#define ETHER_ADDR_LEN 6
typedef struct SceNetEtherAddr {
	uint8_t data[ETHER_ADDR_LEN];
} __attribute__((packed)) SceNetEtherAddr;

// Socket Polling Event Listener
typedef struct SceNetAdhocPollSd {
	int id;
	int events;
	int revents;
} __attribute__((packed)) SceNetAdhocPollSd;

// PDP Socket Status
typedef struct SceNetAdhocPdpStat {
	struct SceNetAdhocPdpStat * next;
	int id;
	SceNetEtherAddr laddr;
	uint16_t lport;
	uint32_t rcv_sb_cc;
} __attribute__((packed)) SceNetAdhocPdpStat;

// PTP Socket Status
typedef struct SceNetAdhocPtpStat {
	struct SceNetAdhocPtpStat * next;
	int id;
	SceNetEtherAddr laddr;
	SceNetEtherAddr paddr;
	uint16_t lport;
	uint16_t pport;
	uint32_t snd_sb_cc;
	uint32_t rcv_sb_cc;
	int state;
} __attribute__((packed)) SceNetAdhocPtpStat;

// Gamemode Optional Peer Buffer Data
typedef struct SceNetAdhocGameModeOptData {
	uint32_t size;
	uint32_t flag;
	uint64_t last_recv;
} __attribute__((packed)) SceNetAdhocGameModeOptData;

// Gamemode Buffer Status
typedef struct SceNetAdhocGameModeBufferStat {
	struct SceNetAdhocGameModeBufferStat * next;
	int id;
	void * ptr;
	uint32_t size;
	uint32_t master;
	SceNetAdhocGameModeOptData opt;
} __attribute__((packed)) SceNetAdhocGameModeBufferStat;

#endif
