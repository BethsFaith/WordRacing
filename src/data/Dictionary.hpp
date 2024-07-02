//
// Created by BethsFaith on 27.06.2024.
//

#ifndef RACING_IN_ENGLISH_DICTIONARY_HPP
#define RACING_IN_ENGLISH_DICTIONARY_HPP

#include "Serializable.hpp"

namespace Data {
    class Dictionary : public Serializable {
    public:
        explicit Dictionary(QObject *parent = nullptr);

        void serialize(QJsonObject &jsonObject) const override;
        void deserialize(const QJsonObject &jsonObject) override;

        void setName(const QString &name);
        void setLanguageId(int languageId);

        [[nodiscard]] const QString &getName() const;
        [[nodiscard]] int getLanguageId() const;

    private:
        QString _name;
        int _languageId = Data::NULL_ID;
    };
}

#endif //RACING_IN_ENGLISH_DICTIONARY_HPP
