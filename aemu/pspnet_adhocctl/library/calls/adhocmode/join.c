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
 * Join discovered Network
 * @param scan_info Discovered Network
 * @return 0 on success or... ADHOCCTL_NOT_INITIALIZED, ADHOCCTL_INVALID_ARG, ADHOCCTL_BUSY
 */
int proNetAdhocctlJoin(const SceNetAdhocctlScanInfo * scan_info)
{
	// Library initialized
	if(_init)
	{
		// Valid Argument
		if(scan_info != NULL)
		{
			// We can ignore minor connection process differences here
			return proNetAdhocctlCreate(&scan_info->group_name);
		}
		
		// Invalid Argument
		return ADHOCCTL_INVALID_ARG;
	}
	
	// Uninitialized Library
	return ADHOCCTL_NOT_INITIALIZED;
}
