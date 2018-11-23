/*
 * LibrePCB - Professional EDA for everyone!
 * Copyright (C) 2013 LibrePCB Developers, see AUTHORS.md for contributors.
 * https://librepcb.org/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBREPCB_LIBRARY_MSGNAMENOTTITLECASE_H
#define LIBREPCB_LIBRARY_MSGNAMENOTTITLECASE_H

/*******************************************************************************
 *  Includes
 ******************************************************************************/
#include "libraryelementcheckmessage.h"

#include <librepcb/common/elementname.h>

#include <QtCore>

/*******************************************************************************
 *  Namespace / Forward Declarations
 ******************************************************************************/
namespace librepcb {
namespace library {

/*******************************************************************************
 *  Class MsgNameNotTitleCase
 ******************************************************************************/

/**
 * @brief The MsgNameNotTitleCase class
 */
class MsgNameNotTitleCase final : public LibraryElementCheckMessage {
  Q_DECLARE_TR_FUNCTIONS(MsgNameNotTitleCase)

public:
  // Constructors / Destructor
  MsgNameNotTitleCase() = delete;
  explicit MsgNameNotTitleCase(const ElementName& name) noexcept;
  MsgNameNotTitleCase(const MsgNameNotTitleCase& other) noexcept
    : LibraryElementCheckMessage(other), mName(other.mName) {}
  virtual ~MsgNameNotTitleCase() noexcept;

  const ElementName& getName() const noexcept { return mName; }
  ElementName getFixedName() const noexcept { return getFixedName(mName); }

  static bool        isTitleCase(const ElementName& name) noexcept;
  static ElementName getFixedName(const ElementName& name) noexcept;

private:
  ElementName mName;
};

/*******************************************************************************
 *  End of File
 ******************************************************************************/

}  // namespace library
}  // namespace librepcb

#endif  // LIBREPCB_LIBRARY_MSGNAMENOTTITLECASE_H
