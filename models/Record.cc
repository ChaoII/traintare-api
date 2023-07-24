/**
 *
 *  Record.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Record.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::sqlite3;

const std::string Record::Cols::_id = "id";
const std::string Record::Cols::_last_timestamp = "last_timestamp";
const std::string Record::Cols::_dir_name = "dir_name";
const std::string Record::primaryKeyName = "id";
const bool Record::hasPrimaryKey = true;
const std::string Record::tableName = "record";

const std::vector<typename Record::MetaData> Record::metaData_={
{"id","uint64_t","integer",8,1,1,1},
{"last_timestamp","std::string","text",0,0,0,1},
{"dir_name","std::string","text",0,0,0,0}
};
const std::string &Record::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Record::Record(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            id_=std::make_shared<uint64_t>(r["id"].as<uint64_t>());
        }
        if(!r["last_timestamp"].isNull())
        {
            lastTimestamp_=std::make_shared<std::string>(r["last_timestamp"].as<std::string>());
        }
        if(!r["dir_name"].isNull())
        {
            dirName_=std::make_shared<std::string>(r["dir_name"].as<std::string>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 3 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            id_=std::make_shared<uint64_t>(r[index].as<uint64_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            lastTimestamp_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            dirName_=std::make_shared<std::string>(r[index].as<std::string>());
        }
    }

}

Record::Record(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 3)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[0]].asUInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            lastTimestamp_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            dirName_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
}

Record::Record(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<uint64_t>((uint64_t)pJson["id"].asUInt64());
        }
    }
    if(pJson.isMember("last_timestamp"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["last_timestamp"].isNull())
        {
            lastTimestamp_=std::make_shared<std::string>(pJson["last_timestamp"].asString());
        }
    }
    if(pJson.isMember("dir_name"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["dir_name"].isNull())
        {
            dirName_=std::make_shared<std::string>(pJson["dir_name"].asString());
        }
    }
}

void Record::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 3)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[0]].asUInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            lastTimestamp_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            dirName_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
}

void Record::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<uint64_t>((uint64_t)pJson["id"].asUInt64());
        }
    }
    if(pJson.isMember("last_timestamp"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["last_timestamp"].isNull())
        {
            lastTimestamp_=std::make_shared<std::string>(pJson["last_timestamp"].asString());
        }
    }
    if(pJson.isMember("dir_name"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["dir_name"].isNull())
        {
            dirName_=std::make_shared<std::string>(pJson["dir_name"].asString());
        }
    }
}

const uint64_t &Record::getValueOfId() const noexcept
{
    const static uint64_t defaultValue = uint64_t();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<uint64_t> &Record::getId() const noexcept
{
    return id_;
}
void Record::setId(const uint64_t &pId) noexcept
{
    id_ = std::make_shared<uint64_t>(pId);
    dirtyFlag_[0] = true;
}
const typename Record::PrimaryKeyType & Record::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &Record::getValueOfLastTimestamp() const noexcept
{
    const static std::string defaultValue = std::string();
    if(lastTimestamp_)
        return *lastTimestamp_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Record::getLastTimestamp() const noexcept
{
    return lastTimestamp_;
}
void Record::setLastTimestamp(const std::string &pLastTimestamp) noexcept
{
    lastTimestamp_ = std::make_shared<std::string>(pLastTimestamp);
    dirtyFlag_[1] = true;
}
void Record::setLastTimestamp(std::string &&pLastTimestamp) noexcept
{
    lastTimestamp_ = std::make_shared<std::string>(std::move(pLastTimestamp));
    dirtyFlag_[1] = true;
}

const std::string &Record::getValueOfDirName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(dirName_)
        return *dirName_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Record::getDirName() const noexcept
{
    return dirName_;
}
void Record::setDirName(const std::string &pDirName) noexcept
{
    dirName_ = std::make_shared<std::string>(pDirName);
    dirtyFlag_[2] = true;
}
void Record::setDirName(std::string &&pDirName) noexcept
{
    dirName_ = std::make_shared<std::string>(std::move(pDirName));
    dirtyFlag_[2] = true;
}
void Record::setDirNameToNull() noexcept
{
    dirName_.reset();
    dirtyFlag_[2] = true;
}

void Record::updateId(const uint64_t id)
{
    id_ = std::make_shared<uint64_t>(id);
}

const std::vector<std::string> &Record::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "last_timestamp",
        "dir_name"
    };
    return inCols;
}

void Record::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getLastTimestamp())
        {
            binder << getValueOfLastTimestamp();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getDirName())
        {
            binder << getValueOfDirName();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Record::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    if(dirtyFlag_[2])
    {
        ret.push_back(getColumnName(2));
    }
    return ret;
}

void Record::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getLastTimestamp())
        {
            binder << getValueOfLastTimestamp();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getDirName())
        {
            binder << getValueOfDirName();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Record::toJson() const
{
    Json::Value ret;
    if(getId())
    {
        ret["id"]=(Json::UInt64)getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getLastTimestamp())
    {
        ret["last_timestamp"]=getValueOfLastTimestamp();
    }
    else
    {
        ret["last_timestamp"]=Json::Value();
    }
    if(getDirName())
    {
        ret["dir_name"]=getValueOfDirName();
    }
    else
    {
        ret["dir_name"]=Json::Value();
    }
    return ret;
}

Json::Value Record::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 3)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getId())
            {
                ret[pMasqueradingVector[0]]=(Json::UInt64)getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getLastTimestamp())
            {
                ret[pMasqueradingVector[1]]=getValueOfLastTimestamp();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getDirName())
            {
                ret[pMasqueradingVector[2]]=getValueOfDirName();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getId())
    {
        ret["id"]=(Json::UInt64)getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getLastTimestamp())
    {
        ret["last_timestamp"]=getValueOfLastTimestamp();
    }
    else
    {
        ret["last_timestamp"]=Json::Value();
    }
    if(getDirName())
    {
        ret["dir_name"]=getValueOfDirName();
    }
    else
    {
        ret["dir_name"]=Json::Value();
    }
    return ret;
}

bool Record::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("last_timestamp"))
    {
        if(!validJsonOfField(1, "last_timestamp", pJson["last_timestamp"], err, true))
            return false;
    }
    else
    {
        err="The last_timestamp column cannot be null";
        return false;
    }
    if(pJson.isMember("dir_name"))
    {
        if(!validJsonOfField(2, "dir_name", pJson["dir_name"], err, true))
            return false;
    }
    return true;
}
bool Record::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                const std::vector<std::string> &pMasqueradingVector,
                                                std::string &err)
{
    if(pMasqueradingVector.size() != 3)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty())
      {
          if(pJson.isMember(pMasqueradingVector[0]))
          {
              if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[1].empty())
      {
          if(pJson.isMember(pMasqueradingVector[1]))
          {
              if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[1] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[2].empty())
      {
          if(pJson.isMember(pMasqueradingVector[2]))
          {
              if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                  return false;
          }
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Record::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("last_timestamp"))
    {
        if(!validJsonOfField(1, "last_timestamp", pJson["last_timestamp"], err, false))
            return false;
    }
    if(pJson.isMember("dir_name"))
    {
        if(!validJsonOfField(2, "dir_name", pJson["dir_name"], err, false))
            return false;
    }
    return true;
}
bool Record::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                              const std::vector<std::string> &pMasqueradingVector,
                                              std::string &err)
{
    if(pMasqueradingVector.size() != 3)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
      {
          if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
              return false;
      }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
      if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
      {
          if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
              return false;
      }
      if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
      {
          if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
              return false;
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Record::validJsonOfField(size_t index,
                              const std::string &fieldName,
                              const Json::Value &pJson,
                              std::string &err,
                              bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(isForCreation)
            {
                err="The automatic primary key cannot be set";
                return false;
            }
            if(!pJson.isUInt64())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 2:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        default:
            err="Internal error in the server";
            return false;
    }
    return true;
}
