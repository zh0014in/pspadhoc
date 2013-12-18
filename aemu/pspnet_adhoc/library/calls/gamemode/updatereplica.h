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

#ifndef _GAMEMODE_UPDATEREPLICA_H_
#define _GAMEMODE_UPDATEREPLICA_H_

/**
 * Adhoc Emulator Gamemode Peer Replica Buffer Updater
 * @param id Replica ID
 * @param opt OUT: Optional Replica Information (NULL can be passed)
 * @return 0 on success or... ADHOC_NOT_INITIALIZED, ADHOC_NOT_IN_GAMEMODE, ADHOC_ALREADY_CREATED, WLAN_INVALID_ARG
 */
int proNetAdhocGameModeUpdateReplica(int id, SceNetAdhocGameModeOptData * opt);

#endif
