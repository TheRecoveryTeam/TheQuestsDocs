#include "userloginresponse.h"

data_structures::UserLoginResponse::UserLoginResponse(
        const QString& id,
        const QString& nickname,
        const QString& email,
        const QString& token):
    id(id), nickname(nickname), email(email), token(token)
{ }
