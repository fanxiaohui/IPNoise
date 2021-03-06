/*
 * $Id$
 *
 * DEBUG: section 16    Cache Manager API
 *
 */

#ifndef SQUID_MGR_ACTION_PARAMS_H
#define SQUID_MGR_ACTION_PARAMS_H

#include "HttpRequestMethod.h"
#include "ipc/forward.h"
#include "mgr/QueryParams.h"

namespace Mgr
{

/// Cache Manager Action parameters extracted from the user request
class ActionParams
{
public:
    ActionParams();

    explicit ActionParams(const Ipc::TypedMsgHdr &msg); ///< load from msg
    void pack(Ipc::TypedMsgHdr &msg) const; ///< store into msg

public:
    /* details of the client HTTP request that caused the action */
    String httpUri; ///< HTTP request URI
    _method_t httpMethod; ///< HTTP request method
    request_flags httpFlags; ///< HTTP request flags
    String httpOrigin;       ///< HTTP Origin: header (if any)

    /* action parameters extracted from the client HTTP request */
    String actionName; ///< action name (and credentials realm)
    String userName; ///< user login name; currently only used for logging
    String password; ///< user password; used for acceptance check and cleared
    QueryParams queryParams;
};

} // namespace Mgr

std::ostream &operator <<(std::ostream &os, const Mgr::ActionParams &params);

#endif /* SQUID_MGR_ACTION_PARAMS_H */
