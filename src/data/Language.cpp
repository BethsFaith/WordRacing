//
// Created by BethsFaith on 27.06.2024.
//

#include "Language.hpp"

namespace Data {
    Language::Language(QObject* parent) : Serializable(Data::LANGUAGE, parent) {}

    void Language::serialize(QJsonObject &jsonObject) const {
        Serializable::serialize(jsonObject);

        jsonObject["name"] = _name;
    }

    void Language::deserialize(const QJsonObject &jsonObject) {
        Serializable::deserialize(jsonObject);

        _name = jsonObject["name"].toString();
    }

    void Language::setName(const QString &name) {
        _name = name;
    }

    const QString &Language::getName() const {
        return _name;
    }
} // Data