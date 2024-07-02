//
// Created by BethsFaith on 27.06.2024.
//

#include "Dictionary.hpp"

namespace Data {
    Dictionary::Dictionary(QObject *parent) : Serializable(Data::DICTIONARY, parent) {}

    void Dictionary::serialize(QJsonObject &jsonObject) const {
        Serializable::serialize(jsonObject);

        jsonObject["name"] = _name;
        jsonObject["language_id"] = _languageId;
    }

    void Dictionary::deserialize(const QJsonObject &jsonObject) {
        Serializable::deserialize(jsonObject);

        _name = jsonObject["name"].toString();
        _languageId = jsonObject["language_id"].toInt();
    }

    void Dictionary::setName(const QString &name) {
        _name = name;
    }

    void Dictionary::setLanguageId(int languageId) {
        _languageId = languageId;
    }

    const QString &Dictionary::getName() const {
        return _name;
    }

    int Dictionary::getLanguageId() const {
        return _languageId;
    }
}