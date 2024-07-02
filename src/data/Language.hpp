//
// Created by BethsFaith on 27.06.2024.
//

#ifndef FOREIGNRACING_LANGUAGE_HPP
#define FOREIGNRACING_LANGUAGE_HPP

#include "Serializable.hpp"

namespace Data {
    class Language : public Serializable {
    public:
        explicit Language(QObject* parent = nullptr);

        void serialize(QJsonObject &jsonObject) const override;
        void deserialize(const QJsonObject &jsonObject) override;

        void setName(const QString &name);

        [[nodiscard]] const QString &getName() const;

    private:
        QString _name;
    };
} // Data

#endif //FOREIGNRACING_LANGUAGE_HPP
