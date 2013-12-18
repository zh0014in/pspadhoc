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

#include "../../common.h"

/**
 * Leave current Network
 * @return 0 on success or... ADHOCCTL_NOT_INITIALIZED, ADHOCCTL_BUSY
 */
int proNetAdhocctlDisconnect(void)
{
	// Library initialized
	if(_init == 1)
	{
		// Connected State (Adhoc Mode)
		if(_thread_status == ADHOCCTL_STATE_CONNECTED)
		{
			// Clear Network Name
			memset(&_parameter.group_name, 0, sizeof(_parameter.group_name));
			
			// Set Disconnected State
			_thread_status = ADHOCCTL_STATE_DISCONNECTED;
			
			// Set HUD Connection Status
			setConnectionStatus(0);
			
			// Prepare Packet
			uint8_t opcode = OPCODE_DISCONNECT;
			
			// Acquire Network Lock
			_acquireNetworkLock();
			
			// Send Disconnect Request Packet
			sceNetInetSend(_metasocket, &opcode, 1, INET_MSG_DONTWAIT);
			
			// Free Network Lock
			_freeNetworkLock();
			
			// Multithreading Lock
			_acquirePeerLock();
			
			// Clear Peer List
			_freeFriendsRecursive(_friends);
			
			// Delete Peer Reference
			_friends = NULL;
			
			// Multithreading Unlock
			_freePeerLock();
		}
		
		// Notify Event Handlers (even if we weren't connected, not doing this will freeze games like God Eater, which expect this behaviour)
		int i = 0; for(; i < ADHOCCTL_MAX_HANDLER; i++)
		{
			// Active Handler
			if(_event_handler[i] != NULL) _event_handler[i](ADHOCCTL_EVENT_DISCONNECT, 0, _event_args[i]);
		}
		
		// Return Success
		return 0;
	}
	
	// Library uninitialized
	return ADHOCCTL_NOT_INITIALIZED;
}
