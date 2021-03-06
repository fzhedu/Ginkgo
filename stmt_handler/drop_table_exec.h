/*
 * Copyright [2012-2015] DaSE@ECNU
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * /CLAIMS/stmt_handler/drop_table_exec.h
 *
 *  Created on: Nov 18, 2015
 *      Author: yuyang
 *		   Email: youngfish93@hotmail.com
 *
 *	Modified on : Aug 8, 2017
 *      Author: zyhe
 *       Email: hzylab@gmail.com
 *
 * Description:
 *
 */

#ifndef STMT_HANDLER_DROP_TABLE_EXEC_H_
#define STMT_HANDLER_DROP_TABLE_EXEC_H_

#include <string>
#include "../stmt_handler/stmt_exec.h"
#include "../sql_parser/ast_node/ast_drop_stmt.h"
namespace claims {
namespace stmt_handler {
/**
 * @brief
 */
class DropTableExec : public StmtExec {
 public:
  DropTableExec(AstNode* stmt);  // NOLINT
  virtual ~DropTableExec();
  friend class DropProjExec;
  friend class TruncateTableExec;
  RetCode Execute(ExecutedResult* exec_result);

 private:
  /**
   * @brief to check the table with given name, whether it is a base table or a
   * del table. If the return value is true, then the table is the base table,
   * if not, the table is the del table.
   * @param table_name the name of the given table
   */
  static bool CheckBaseTbl(const string& table_name);
  /**
   * @brief delete the table from the catalog and the delete the associated
   * files in the disk or in the hdfs
   * @param table_name
   * @return
   */
  RetCode DropTable(const string& table_name);

  /**
   * @brief delete the table information from the catalog
   * @param table_name
   * @return
   */
  RetCode DropTableFromCatalog(const string& table_name);

  /**
   * @brief delete the table files from the stroage
   * @param table_name
   * @return
   */
  static RetCode DeleteTableFiles(const string& table_name);

  /**
   * @brief delete all files of one projection from the stroage
   * @param table_name, projection_id
   * @author zyhe
   * @return
   */
  static RetCode DeleteProjectionFiles(const string& table_name,
                                       const string& proj_id);

  /**
   * @brief call the UnbindingEntireProjection() function to free the memory in
   * the memory pool. The memory return to the memory pool rather than return to
   * the operating system directly. It causes when you apply the memory next
   * time thread will use the memory pool first.
   * @param table_name
   * @author zyhe
   * @return
   */
  static bool FreeTableFromMemory(const string& table_name);

 private:
  AstDropTable* drop_table_ast_;
};

} /* namespace stmt_handler */
} /* namespace claims */

#endif  //  STMT_HANDLER_DROP_TABLE_EXEC_H_
