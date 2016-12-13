/*
   SSSD

   KCM Server - private header file

   Copyright (C) Red Hat, 2016

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __KCMSRV_OPS_H__
#define __KCMSRV_OPS_H__

#include "config.h"

#include <sys/types.h>
#include "util/sss_iobuf.h"
#include "responder/kcm/kcmsrv_pvt.h"

struct kcm_op;
struct kcm_op *kcm_get_opt(uint16_t opcode);
const char *kcm_opt_name(struct kcm_op *op);

struct tevent_req *kcm_cmd_send(TALLOC_CTX *mem_ctx,
                                struct tevent_context *ev,
                                struct kcm_resp_ctx *kcm_data,
                                struct cli_creds *client,
                                struct kcm_data *input,
                                struct kcm_op *op);
errno_t kcm_cmd_recv(TALLOC_CTX *mem_ctx,
                     struct tevent_req *req,
                     struct sss_iobuf **_reply);

#endif /* __KCMSRV_OPS_H__ */