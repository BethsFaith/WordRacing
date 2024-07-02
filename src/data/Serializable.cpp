//
// Created by BethsFaith on 27.06.2024.
//

#include "Serializable.hpp"

namespace Data {
    Serializable::Serializable(Type type, QObject* parent) : QObject(parent), _type(type) {}

    void Serializable::serialize(QJsonObject &jsonObject) const {
        jsonObject["id"] = _id;
        jsonObject["type"] = _type;
    }

    void Serializable::deserialize(const QJsonObject &jsonObject) {
        _id = jsonObject["id"].toInt();
        _type = static_cast<Type>(jsonObject["type"].toInt());
    }

    void Serializable::setId(int id) {
        _id = id;
    }

    int Serializable::getId() const {
        return _id;
    }

    Type Serializable::getType() const {
        return _type;
    }
}