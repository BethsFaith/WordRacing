//
// Created by BethsFaith on 27.06.2024.
//

#include "Word.hpp"

namespace Data {
    Word::Word(QObject* parent) : Serializable(Data::WORD, parent) {}

    void Word::serialize(QJsonObject &jsonObject) const {
        Serializable::serialize(jsonObject);

        jsonObject["foreign"] = _foreign;
        jsonObject["original"] = _original;
        jsonObject["dictionaryId"] = _dictionaryId;
    }

    void Word::deserialize(const QJsonObject &jsonObject) {
        Serializable::deserialize(jsonObject);

        _foreign = jsonObject["foreign"].toString();
        _original = jsonObject["original"].toString();
        _dictionaryId = jsonObject["dictionaryId"].toInt();
    }

    void Word::setForeign(const QString &foreign) {
        _foreign = foreign;
    }

    void Word::setOriginal(const QString &original) {
        _original = original;
    }

    void Word::setDictionaryId(int id) {
        _dictionaryId = id;
    }

    const QString &Word::getForeign() const {
        return _foreign;
    }

    const QString &Word::getOriginal() const {
        return _original;
    }

    int Word::getDictionaryId() const {
        return _dictionaryId;
    }
}