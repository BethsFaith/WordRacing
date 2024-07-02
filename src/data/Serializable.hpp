//
// Created by BethsFaith on 27.06.2024.
//

#ifndef RACING_IN_ENGLISH_ISERIALIZABLE_HPP
#define RACING_IN_ENGLISH_ISERIALIZABLE_HPP

#include <QJsonObject>

#include "Type.hpp"
#include "Const.hpp"

namespace Data {
    class Serializable : public QObject { //Base
    public:
        explicit Serializable(Type type, QObject* parent = nullptr);
        ~Serializable() override = default;

        virtual void serialize(QJsonObject &jsonObject) const;
        virtual void deserialize(const QJsonObject &jsonObject);

        void setId(int id);

        [[nodiscard]] int getId() const;
        [[nodiscard]] Type getType() const;

    private:
        int _id{NULL_ID};
        Type _type;
    };
}
//Q_DECLARE_METATYPE(Data::ISerializable)

#endif //RACING_IN_ENGLISH_ISERIALIZABLE_HPP
