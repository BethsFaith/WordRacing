//
// Created by BethsFaith on 27.06.2024.
//

#ifndef RACING_IN_ENGLISH_STORAGE_HPP
#define RACING_IN_ENGLISH_STORAGE_HPP

#include <QFile>
#include <QJsonDocument>

#include "data/Serializable.hpp"
#include "data/Dictionary.hpp"
#include "data/Language.hpp"
#include "data/Word.hpp"

class Storage : public QObject {
public:
    explicit Storage(QObject* parent = nullptr);

    void save(QString path);
    void load(QString path);

    void add(Data::Serializable* data);
    void update(Data::Serializable* data);
    void remove(Data::Type type, int id);

    void clear();

    Data::Serializable* get(Data::Type type, int id);
    Data::Serializable* getByField(Data::Type type, const char *fieldName, const QVariant& fieldValue);
    QList<Data::Serializable*> getByType(Data::Type);
private:
    static int getKey(Data::Type type, int id);
    static int getKey(Data::Serializable* data);

    void pullDataObjects(const QJsonArray& jsonArray, Data::Type type);
    void updateCounter(Data::Type type, int id);
    void assignId(Data::Serializable* id);

    static std::map<Data::Type, QString> names;

    std::map<int, Data::Serializable*> _data;
    std::map<Data::Type, int> _maxDataIds;
};

#endif //RACING_IN_ENGLISH_STORAGE_HPP
