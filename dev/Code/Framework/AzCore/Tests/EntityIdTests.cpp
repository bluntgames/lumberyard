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
#include <TestTypes.h>

#include <AzCore/Component/EntityId.h>

class EntityIdTests
    : public UnitTest::AllocatorsFixture
{
};

TEST_F(EntityIdTests, GreaterThan_RightIdIsLesser_ReturnsTrue)
{
    AZ::EntityId leftId(10);
    AZ::EntityId rightId(0);
    EXPECT_TRUE(leftId > rightId);
}

TEST_F(EntityIdTests, GreaterThan_RightIdIsGreater_ReturnsFalse)
{
    AZ::EntityId leftId(15);
    AZ::EntityId rightId(20);
    EXPECT_FALSE(leftId > rightId);
}

TEST_F(EntityIdTests, GreaterThan_RightIdIsTheSame_ReturnsFalse)
{
    AZ::EntityId leftId(15);
    AZ::EntityId rightId(15);
    EXPECT_FALSE(leftId > rightId);
}

TEST_F(EntityIdTests, GreaterThan_RightIdInvalid_ReturnsFalse)
{
    AZ::EntityId leftId(15);
    AZ::EntityId rightId(AZ::EntityId::InvalidEntityId);
    EXPECT_FALSE(leftId > rightId);
}

TEST_F(EntityIdTests, GreaterThan_LeftIdInvalid_ReturnsTrue)
{
    AZ::EntityId leftId(AZ::EntityId::InvalidEntityId);
    AZ::EntityId rightId(30);
    EXPECT_TRUE(leftId > rightId);
}

TEST_F(EntityIdTests, LessThan_RightIdIsLesser_ReturnsFalse)
{
    AZ::EntityId leftId(10);
    AZ::EntityId rightId(0);
    EXPECT_FALSE(leftId < rightId);
}

TEST_F(EntityIdTests, LessThan_RightIdIsGreater_ReturnsTrue)
{
    AZ::EntityId leftId(15);
    AZ::EntityId rightId(20);
    EXPECT_TRUE(leftId < rightId);
}

TEST_F(EntityIdTests, LessThan_RightIdIsTheSame_ReturnsFalse)
{
    AZ::EntityId leftId(15);
    AZ::EntityId rightId(15);
    EXPECT_FALSE(leftId < rightId);
}

TEST_F(EntityIdTests, LessThan_RightIdInvalid_ReturnsTrue)
{
    AZ::EntityId leftId(15);
    AZ::EntityId rightId(AZ::EntityId::InvalidEntityId);
    EXPECT_TRUE(leftId < rightId);
}

TEST_F(EntityIdTests, LessThan_LeftIdInvalid_ReturnsFalse)
{
    AZ::EntityId leftId(AZ::EntityId::InvalidEntityId);
    AZ::EntityId rightId(30);
    EXPECT_FALSE(leftId < rightId);
}

TEST_F(EntityIdTests, IsValid_EntityIdIsNotInvalidEntityId_ReturnsTrue)
{
    AZ::EntityId entityId(15);
    EXPECT_TRUE(entityId.IsValid());
}

TEST_F(EntityIdTests, IsValid_EntityIdIsInvalidEntityId_ReturnsFalse)
{
    AZ::EntityId entityId(AZ::EntityId::InvalidEntityId);
    EXPECT_FALSE(entityId.IsValid());
}

TEST_F(EntityIdTests, SetInvalid_ValidEntity_BecomesInvalid)
{
    AZ::EntityId entityId(10);
    entityId.SetInvalid();
    EXPECT_FALSE(entityId.IsValid());
}

TEST_F(EntityIdTests, Equals_SameIds_ReturnsTrue)
{
    AZ::EntityId leftId(20);
    AZ::EntityId rightId(20);
    EXPECT_TRUE(leftId == rightId);
}

TEST_F(EntityIdTests, Equals_DifferentIds_ReturnsFalse)
{
    AZ::EntityId leftId(80);
    AZ::EntityId rightId(20);
    EXPECT_FALSE(leftId == rightId);
}

TEST_F(EntityIdTests, NotEquals_SameIds_ReturnsFalse)
{
    AZ::EntityId leftId(20);
    AZ::EntityId rightId(20);
    EXPECT_FALSE(leftId != rightId);
}

TEST_F(EntityIdTests, NotEquals_DifferentIds_ReturnsTrue)
{
    AZ::EntityId leftId(80);
    AZ::EntityId rightId(20);
    EXPECT_TRUE(leftId != rightId);
}

TEST_F(EntityIdTests, Constructor_Default_IsInvalidEntityId)
{
    AZ::EntityId entityId;
    AZ::EntityId invalidId(AZ::EntityId::InvalidEntityId);
    EXPECT_EQ((AZ::u64)entityId, (AZ::u64)invalidId);
}