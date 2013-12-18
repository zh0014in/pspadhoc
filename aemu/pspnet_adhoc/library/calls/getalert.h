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

#ifndef _GETALERT_H_
#define _GETALERT_H_

/**
 * Adhoc Emulator Socket Alert Getter
 * @param id Socket File Descriptor
 * @param flag OUT: Alert Bitflags
 * @return 0 on success or... ADHOC_NOT_INITIALIZED, ADHOC_INVALID_SOCKET_ID, ADHOC_INVALID_ARG
 */
int proNetAdhocGetSocketAlert(int id, int * flag);

#endif
