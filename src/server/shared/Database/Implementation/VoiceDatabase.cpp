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

#include "VoiceDatabase.h"

void VoiceDatabaseConnection::DoPrepareStatements()
{
    if (!m_reconnecting)
        m_stmts.resize(MAX_VOICEDATABASE_STATEMENTS);

    PREPARE_STATEMENT(VOICE_CREATE_GUILD_CHANNEL, "INSERT INTO `x1_channels` (`server_id`, `channel_id`, `parent_id`, `name`, `inheritacl`) VALUES ('1', ?, '1', ?, '1')", CONNECTION_SYNCH)
    PREPARE_STATEMENT(VOICE_CREATE_GUILD_CHANNEL_INFO, "INSERT INTO `x1_channels` (`server_id`, `channel_id`, `key`, `value`, `inheritacl`) VALUES ('1', ?, '0', ?)", CONNECTION_SYNCH)
	PREPARE_STATEMENT(VOICE_CREATE_GUILD_GROUP, "", CONNECTION_SYNCH)
    PREPARE_STATEMENT(VOICE_CREATE_GUILD_ACL, "INSERT INTO `x1_acl` (`server_id`, `channel_id`, `priority`, `user_id`, `group_name`, `apply_here`, `apply_sub`, `grantpriv`, `revokepriv`) VALUES ('1', ?, '7', NULL, ?, '1', '1', '782', '1265')", CONNECTION_SYNCH)
    PREPARE_STATEMENT(VOICE_REVOKE_ALL_ACL, "INSERT INTO `x1_acl` (`server_id`, `channel_id`, `priority`, `user_id`, `group_name`, `apply_here`, `apply_sub`, `grantpriv`, `revokepriv`) VALUES ('1', ?, '5', NULL, all, '1', '1', '780', '1267')", CONNECTION_SYNCH)
    PREPARE_STATEMENT(VOICE_ADD_GUILD_MASTER_ACL, "INSERT INTO `x1_acl` (`server_id`, `channel_id`, `priority`, `user_id`, `group_name`, `apply_here`, `apply_sub`, `grantpriv`, `revokepriv`) VALUES ('1', ?, '6', ?, NULL, '1', '1', '894', '1153')", CONNECTION_SYNCH)
    PREPARE_STATEMENT(VOICE_ADD_GUILD_MASTER, "INSERT INTO `x1_users` (`server_id`, `user_id`, `name`, `pw`) VALUES ('1', ?, ?, ?);", CONNECTION_SYNCH)
    PREPARE_STATEMENT(VOICE_ADD_GUILD_MEMBER, "", CONNECTION_SYNCH)
    PREPARE_STATEMENT(VOICE_DELETE_GUILD_CHANNEL, "", CONNECTION_SYNCH)
}
