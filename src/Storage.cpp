//
// Created by BethsFaith on 27.06.2024.
//

#include <QJsonArray>
#include "Storage.hpp"

std::map<Data::Type, QString> Storage::names = {};

Storage::Storage(QObject *parent) : QObject(parent) {
    names[Data::Type::WORD] = "words";
    names[Data::Type::LANGUAGE] = "language";
    names[Data::Type::DICTIONARY] = "dictionary";
}

void Storage::save(QString path) {
    QFile fileStream{path};

    fileStream.open(QIODevice::WriteOnly);

    QJsonObject object;
    std::map<Data::Type, QJsonArray> typeObjects;
    for (const auto& pair : _data) { // pair.first - Data::Type, pair.second - Data::Serializable*
        if (pair.second == nullptr) {
            return;
        }

        auto type = pair.second->getType();
        if (!typeObjects.contains(type)) {
            typeObjects[type] = QJsonArray();
        }

        QJsonObject dataObject;
        pair.second->serialize(dataObject);

        typeObjects[type].push_back(dataObject);
    }

    for (const auto& pair : typeObjects) {
        object[names[pair.first]] = pair.second;
    }

    QJsonDocument jsonDoc(object);
    fileStream.write(jsonDoc.toJson());

    fileStream.close();
}

void Storage::load(QString path) {
    QFile fileStream{path};

    fileStream.open(QIODevice::ReadOnly);

    auto jsonDoc = QJsonDocument::fromJson(fileStream.readAll());

    QJsonObject jsonObj;
    if (!jsonDoc.isNull()) {
        jsonObj = jsonDoc.object();

        for (const auto& pair : names) {
            pullDataObjects(jsonObj.value(pair.second).toArray(), pair.first);
        }
    }
    fileStream.close();
}

void Storage::pullDataObjects(const QJsonArray& jsonArray, Data::Type type) {
    std::function<Data::Serializable*(void)> createData;

    switch (type) {
        case Data::LANGUAGE:
            createData = [](){
                return new Data::Language();
            };
            break;
        case Data::WORD:
            createData = [](){
                return new Data::Word();
            };
            break;
        case Data::DICTIONARY:
            createData = [](){
                return nullptr;
            };
            break;
    }

    int maxId = 0;
    for (auto elem : jsonArray) {
        auto elemObj = elem.toObject();

        auto data = createData();
        if (data != nullptr) {
            data->setParent(this);
            data->deserialize(elemObj);

            if (data->getId() > maxId) {
                maxId = data->getId();
            }

            add(data);
        }
    }

    updateCounter(type, maxId);
}

void Storage::updateCounter(Data::Type type, int id) {
    if (_maxDataIds.contains(type)) {
        if (_maxDataIds[type] > id) {
            return;
        }
    }

    _maxDataIds[type] = id;
}

void Storage::add(Data::Serializable *data) {
    assignId(data);

    _data[getKey(data)] = data;
}

void Storage::assignId(Data::Serializable *data) {
    if (!_maxDataIds.contains(data->getType())) {
        _maxDataIds[data->getType()] = Data::NULL_ID;
    }

    ++_maxDataIds[data->getType()];

    data->setId(_maxDataIds[data->getType()]);
}

void Storage::update(Data::Serializable *data) {
    _data[getKey(data)] = data;
}

void Storage::remove(Data::Type type, int id) {
    auto key = getKey(type, id);
    if (_data.contains(key)) {
        auto data = _data[key];

        _data.erase(key);

        delete data;
    }
}

void Storage::clear() {
    _data.clear();
    _maxDataIds.clear();
}

Data::Serializable *Storage::get(Data::Type type, int id) {
    auto key = getKey(type, id);

    if (_data.contains(key)) {
        return _data[key];
    }

    return nullptr;
}

Data::Serializable *Storage::getByField(Data::Type type, const char *fieldName, const QVariant& fieldValue) {
    auto startKey = getKey(type, Data::NULL_ID);
    auto endKey = getKey(type, _maxDataIds[type]);

    auto it = _data.lower_bound(startKey); // logN
    auto end = _data.upper_bound(endKey); // logN

    while (it != end) {
        if (it->second->property(fieldName) == fieldValue) {
            return it->second;
        }
    }

    return nullptr;
}

QList<Data::Serializable *> Storage::getByType(Data::Type type) {
    QList<Data::Serializable *> res;

    auto startKey = getKey(type, Data::NULL_ID);
    auto endKey = getKey(type, _maxDataIds[type]);

    auto it = _data.lower_bound(startKey); // logN
    auto end = _data.upper_bound(endKey); // logN

    while (it != end) {
        res.push_back(it->second);
    }

    return res;
}

int Storage::getKey(Data::Serializable *data) {
    return getKey(data->getType(), data->getId());
}

int Storage::getKey(Data::Type type, int id) {
    const int N = 1000000; // ограничение для id = 99 000 000, для type(тип - enum) = 99

    int number = id + type*N;

    return number;
}
