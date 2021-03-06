//
// Created by dpudov on 12.11.18.
//

#ifndef THEQUESTS_USERCONTROLLER_H
#define THEQUESTS_USERCONTROLLER_H

#include <core/controller/AbstractController.h>
#include <utils/controller/Handler.h>

class UserController : public networkhelper::AbstractController {
public:
    UserController() {
        std::wcout << U("UserController initiated\n");
    }

    void ConfigureRouting() override;

    void InitHandlers() override;

    void CreateUser(const web::http::http_request& message);

    void FindEmail(const web::http::http_request& message);

    void FindNickname(const web::http::http_request& message);

    void LoginUser(const web::http::http_request& message);

    void LogoutUser(const web::http::http_request& message);

    void OauthProcess(const web::http::http_request& message);
private:
    static web::json::value responseNotImpl(const web::http::method &method);
};

#endif //THEQUESTS_USERCONTROLLER_H