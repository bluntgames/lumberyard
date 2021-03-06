/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
// Original file Copyright Crytek GMBH or its affiliates, used under license.

#ifndef CRYINCLUDE_TOOLS_DBAPI_TESTTAUDBAPI_QUERYDEF_H
#define CRYINCLUDE_TOOLS_DBAPI_TESTTAUDBAPI_QUERYDEF_H

//don't use #pragma once
// WHY? That comment is USELESS!

#ifndef QUERY_DEF_START
#   define QUERY_DEF_START(QUERY_GROUP)     enum QUERY_GROUP {
#endif
#ifndef QUERY_DEF_END
#   define QUERY_DEF_END()                  };
#endif
#ifndef QUERY_DEF
#   define QUERY_DEF(QueryID, QueryStr)        QueryID,
#endif

/// Query Definition

QUERY_DEF_START(SW_STATEMENTS)

QUERY_DEF(ST_1, "SELECT GD_LockedBy, GD_OV, GD_CV, GD_HV FROM GDStatus WHERE Name=?")

QUERY_DEF(ST_2, "SELECT TerrainLayers_LockedBy, TerrainLayers_OV, TerrainLayers_CV, TerrainLayers_HV \
																									 FROM GDStatus WHERE Name=?")

QUERY_DEF(ST_3, "SELECT Vegetation_LockedBy, Vegetation_OV, Vegetation_CV, Vegetation_HV \
																								FROM GDStatus WHERE Name=?")

QUERY_DEF_END()


#endif // CRYINCLUDE_TOOLS_DBAPI_TESTTAUDBAPI_QUERYDEF_H
