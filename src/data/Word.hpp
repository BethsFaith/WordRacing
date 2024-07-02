//
// Created by BethsFaith on 27.06.2024.
//

#ifndef RACING_IN_ENGLISH_WORD_HPP
#define RACING_IN_ENGLISH_WORD_HPP

#include "Serializable.hpp"

namespace Data {
    class Word : public Serializable {
    public:
        explicit Word(QObject* parent = nullptr);

        void serialize(QJsonObject &jsonObject) const override;
        void deserialize(const QJsonObject &jsonObject) override;

        void setForeign(const QString &foreign);
        void setOriginal(const QString &original);
        void setDictionaryId(int id);

        [[nodiscard]] const QString &getForeign() const;
        [[nodiscard]] const QString &getOriginal() const;
        [[nodiscard]] int getDictionaryId() const;

    private:
        QString _foreign;
        QString _original;
        int _dictionaryId;
    };
}

#endif //RACING_IN_ENGLISH_WORD_HPP
