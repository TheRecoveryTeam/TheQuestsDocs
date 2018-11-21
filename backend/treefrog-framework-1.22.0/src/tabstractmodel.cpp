/* Copyright (c) 2010-2017, AOYAMA Kazuharu
 * All rights reserved.
 *
 * This software may be used and distributed according to the terms of
 * the New BSD License, which is incorporated herein by reference.
 */

#include <TAbstractModel>
#include <TModelObject>

/*!
  \class TAbstractModel
  \brief The TAbstractModel class is the abstract base class of models,
  providing functionality common to models.
*/

/*!
  Returns true if this model is null; otherwise returns false.
 */
bool TAbstractModel::isNull() const
{
    return modelData()->isNull();
}

/*!
  Returns true if this model is new, not created; otherwise returns false.
 */
bool TAbstractModel::isNew() const
{
    return modelData()->isNull();
}

/*!
  Returns true if this model is not saved; otherwise returns false.
 */
bool TAbstractModel::isSaved() const
{
    return !modelData()->isNull();
}

/*!
  Creates the model as a new data to the data storage.
 */
bool TAbstractModel::create()
{
    return modelData()->create();
}

/*!
  Saves the model to the data storage.

  If the model exists in the data storage, calls update();
  otherwise calls create().
 */
bool TAbstractModel::save()
{
    return modelData()->save();
}

/*!
  Updates the model to the data storage.
 */
bool TAbstractModel::update()
{
    return modelData()->update();
}

/*!
  Removes the model from the data storage.
 */
bool TAbstractModel::remove()
{
    return modelData()->remove();
}

/*!
  Returns a map with all properties of this text format.
 */
QVariantMap TAbstractModel::toVariantMap() const
{
    QVariantMap ret;

    QVariantMap map = modelData()->toVariantMap();
    for (QMapIterator<QString, QVariant> it(map); it.hasNext(); ) {
        it.next();
        ret.insert(fieldNameToVariableName(it.key()), it.value());
    }
    return ret;
}

/*!
  Sets the \a properties.
 */
void TAbstractModel::setProperties(const QVariantMap &properties)
{
    // Creates a map of the original property name and the converted name
    const QStringList moprops = modelData()->propertyNames();
    QMap<QString, QString> mopropMap;
    for (auto &orig : moprops) {
        mopropMap.insert(fieldNameToVariableName(orig), orig);
    }

    QVariantMap props;
    for (QMapIterator<QString, QVariant> it(properties); it.hasNext(); ) {
        it.next();
        const QString &p = mopropMap[it.key()];
        if (!p.isEmpty()) {
            props.insert(p, it.value());
        }
    }

    modelData()->setProperties(props);
}


QString TAbstractModel::variableNameToFieldName(const QString &name) const
{
    for (auto &prop : modelData()->propertyNames()) {
        if (fieldNameToVariableName(prop) == name) {
            return prop;
        }
    }
    return QString();
}


QString TAbstractModel::fieldNameToVariableName(const QString &name)
{
    QString ret;
    bool existsLower = false;
    bool existsUnders = name.contains('_');
    const QLatin1Char Underscore('_');

    ret.reserve(name.length());

    for (int i = 0; i < name.length(); ++i) {
        const QChar &c = name[i];
        if (c == Underscore) {
            if (i > 0 && i + 1 < name.length()) {
                ret += name[++i].toUpper();
            }
        } else {
            if (!existsLower && c.isLower()) {
                existsLower = true;
            }
            ret += (existsLower && !existsUnders) ? c : c.toLower();
        }
    }
    return ret;
}


/*!
  \fn virtual TModelObject *TAbstractModel::modelData()

  This function is reimplemented in subclasses to return a pointer
  to the data stored in the model object.
*/


/*!
  \fn virtual const TModelObject *TAbstractModel::modelData() const

  This function is reimplemented in subclasses to return a pointer
  to the data stored in the model object.
*/
