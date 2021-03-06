//
// Created by dpudov on 12.11.18.
//

#ifndef THEQUESTS_NETWORKUTILS_H
#define THEQUESTS_NETWORKUTILS_H

#include <string>
#include <boost/format.hpp>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <boost/asio.hpp>
#include <boost/algorithm/string.hpp>

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <regex>
//#include <utils/controller/MicroService.h>

namespace networkhelper {

    using HostInetInfo = boost::asio::ip::tcp::resolver::iterator;

    class NetworkUtils {
    private:
        static HostInetInfo queryHostInetInfo();

        static std::string hostIP(unsigned short family);

    public:
        // gets the host IP4 string formatted
        static std::string hostIP4() {
            return hostIP(AF_INET);
        }

        // gets the host IP6 string formatted
        static std::string hostIP6() {

            return hostIP(AF_INET6);
        }

        static std::string hostName() {
            return boost::asio::ip::host_name();
        }
    };

#define ASSIGN_HANDLER(controller, action) [](const web::http::http_request & request) {\
    static_assert(std::is_base_of<networkhelper::AbstractController, controller>::value, "controller class must derive from 'AbstractController'");\
    auto c = controller();\
    try {\
        c.action(request);\
    } catch (const std::exception & ex) {\
        request.reply(web::http::status_codes::InternalError);\
    } catch (...) {\
        request.reply(web::http::status_codes::InternalError);\
    }\
}

}
#endif //THEQUESTS_NETWORKUTILS_H
