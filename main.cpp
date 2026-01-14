//
// Copyright Metaspex - 2021
// mailto:admin@metaspex.com
//

// To test (update 8080 port number to whatever was configured in the web server, typically 8080 for
// Apache and 8081 for Nginx):
// 
// curl http://localhost:8080/test -d '{"message": "Hello"}'
// {"ok":true,"msg":"Hello from 192.168.1.1"}
//
// The server answers the message given in input followed by the IP address it sees as the client's one.
// Note that no carriage return is displayed, this is normal.

#include "hx2a/slot.hpp"
#include "hx2a/service.hpp"
#include "hx2a/http_request.hpp"
#include "hx2a/payloads/reply_msg.hpp"
#include "hx2a/format.hpp"

using namespace hx2a;

// Specification of the query payload.

class query: public element<>
{
  HX2A_ELEMENT(query, "query", element,
	       ((message, "message")));
public:

  slot<string> message;
};

// Specification of the test service. The "test" string will appear at the end of the URI that the server will accept.

auto _test = service<"echo"> // Singleton.
  ([](http_request& r, const rfr<query>& q){
    return make<reply_msg>(true, format(q->message.get(), " from ", r.get_client_ip()));
  });
