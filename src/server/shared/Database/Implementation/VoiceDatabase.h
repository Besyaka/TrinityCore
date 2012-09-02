/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _VOICEDATABASE_H
#define _VOICEDATABASE_H

#include "DatabaseWorkerPool.h"
#include "MySQLConnection.h"

class VoiceDatabaseConnection : public MySQLConnection
{
    public:
        //- Constructors for sync and async connections
        VoiceDatabaseConnection(MySQLConnectionInfo& connInfo) : MySQLConnection(connInfo) {}
        VoiceDatabaseConnection(ACE_Activation_Queue* q, MySQLConnectionInfo& connInfo) : MySQLConnection(q, connInfo) {}

        //- Loads database type specific prepared statements
        void DoPrepareStatements();
};

typedef DatabaseWorkerPool<VoiceDatabaseConnection> VoiceDatabaseWorkerPool;

enum VoiceDatabaseStatements
{
    /*  Naming standard for defines:
        {DB}_{SEL/INS/UPD/DEL/REP}_{Summary of data changed}
        When updating more than one field, consider looking at the calling function
        name for a suiting suffix.
    */

    VOICE_CREATE_GUILD_CHANNEL,
	VOICE_CREATE_GUILD_CHANNEL_INFO,
	VOICE_CREATE_GUILD_GROUP,
	VOICE_CREATE_GUILD_ACL,
	VOICE_REVOKE_ALL_ACL,
	VOICE_ADD_GUILD_MASTER_ACL,
	VOICE_ADD_GUILD_MASTER,
	VOICE_ADD_GUILD_MEMBER,
	VOICE_DELETE_GUILD_CHANNEL,

    MAX_VOICEDATABASE_STATEMENTS,
};

#endif
