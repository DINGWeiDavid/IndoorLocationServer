// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "WifiMap-odb.hxx"

#include <cassert>
#include <cstring>  // std::memcpy


#include <odb/mysql/traits.hxx>
#include <odb/mysql/database.hxx>
#include <odb/mysql/transaction.hxx>
#include <odb/mysql/connection.hxx>
#include <odb/mysql/statement.hxx>
#include <odb/mysql/statement-cache.hxx>
#include <odb/mysql/simple-object-statements.hxx>
#include <odb/mysql/container-statements.hxx>
#include <odb/mysql/exceptions.hxx>
#include <odb/mysql/simple-object-result.hxx>
#include <odb/mysql/enum.hxx>

namespace odb
{
  // WifiMap
  //

  struct access::object_traits_impl< ::WifiMap, id_mysql >::extra_statement_cache_type
  {
    mysql::container_statements_impl< wifi_vec_traits > wifi_vec_;

    extra_statement_cache_type (
      mysql::connection& c,
      image_type&,
      id_image_type&,
      mysql::binding& id,
      mysql::binding&)
    : wifi_vec_ (c, id)
    {
    }
  };

  // wifi_vec_
  //

  const char access::object_traits_impl< ::WifiMap, id_mysql >::wifi_vec_traits::
  select_statement[] =
  "SELECT "
  "`WifiMap_wifi_vec`.`key`, "
  "`WifiMap_wifi_vec`.`value` "
  "FROM `WifiMap_wifi_vec` "
  "WHERE `WifiMap_wifi_vec`.`object_id`=?";

  const char access::object_traits_impl< ::WifiMap, id_mysql >::wifi_vec_traits::
  insert_statement[] =
  "INSERT INTO `WifiMap_wifi_vec` "
  "(`object_id`, "
  "`key`, "
  "`value`) "
  "VALUES "
  "(?, ?, ?)";

  const char access::object_traits_impl< ::WifiMap, id_mysql >::wifi_vec_traits::
  delete_statement[] =
  "DELETE FROM `WifiMap_wifi_vec` "
  "WHERE `object_id`=?";

  void access::object_traits_impl< ::WifiMap, id_mysql >::wifi_vec_traits::
  bind (MYSQL_BIND* b,
        const MYSQL_BIND* id,
        std::size_t id_size,
        data_image_type& d)
  {
    using namespace mysql;

    statement_kind sk (statement_select);
    ODB_POTENTIALLY_UNUSED (sk);

    size_t n (0);

    // object_id
    //
    if (id != 0)
      std::memcpy (&b[n], id, id_size * sizeof (id[0]));
    n += id_size;

    // key
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = d.key_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      d.key_value.capacity ());
    b[n].length = &d.key_size;
    b[n].is_null = &d.key_null;
    n++;

    // value
    //
    b[n].buffer_type = MYSQL_TYPE_LONG;
    b[n].is_unsigned = 0;
    b[n].buffer = &d.value_value;
    b[n].is_null = &d.value_null;
  }

  void access::object_traits_impl< ::WifiMap, id_mysql >::wifi_vec_traits::
  grow (data_image_type& i,
        my_bool* t)
  {
    bool grew (false);

    // key
    //
    if (t[0UL])
    {
      i.key_value.capacity (i.key_size);
      grew = true;
    }

    // value
    //
    t[1UL] = 0;

    if (grew)
      i.version++;
  }

  void access::object_traits_impl< ::WifiMap, id_mysql >::wifi_vec_traits::
  init (data_image_type& i,
        const key_type* k,
        const value_type& v)
  {
    using namespace mysql;

    statement_kind sk (statement_insert);
    ODB_POTENTIALLY_UNUSED (sk);

    bool grew (false);

    // key
    //
    if (k != 0)
    {
      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.key_value.capacity ());
      mysql::value_traits<
          key_type,
          mysql::id_string >::set_image (
        i.key_value,
        size,
        is_null,
        *k);
      i.key_null = is_null;
      i.key_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.key_value.capacity ());
    }

    // value
    //
    {
      bool is_null (false);
      mysql::value_traits<
          value_type,
          mysql::id_long >::set_image (
        i.value_value, is_null, v);
      i.value_null = is_null;
    }

    if (grew)
      i.version++;
  }

  void access::object_traits_impl< ::WifiMap, id_mysql >::wifi_vec_traits::
  init (key_type& k,
        value_type& v,
        const data_image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (db);

    // key
    //
    {
      mysql::value_traits<
          key_type,
          mysql::id_string >::set_value (
        k,
        i.key_value,
        i.key_size,
        i.key_null);
    }

    // value
    //
    {
      mysql::value_traits<
          value_type,
          mysql::id_long >::set_value (
        v,
        i.value_value,
        i.value_null);
    }
  }

  void access::object_traits_impl< ::WifiMap, id_mysql >::wifi_vec_traits::
  insert (const key_type& k, const value_type& v, void* d)
  {
    using namespace mysql;

    statements_type& sts (*static_cast< statements_type* > (d));
    data_image_type& di (sts.data_image ());

    init (di, &k, v);

    if (sts.data_binding_test_version ())
    {
      const binding& id (sts.id_binding ());
      bind (sts.data_bind (), id.bind, id.count, di);
      sts.data_binding_update_version ();
    }

    if (!sts.insert_statement ().execute ())
      throw object_already_persistent ();
  }

  bool access::object_traits_impl< ::WifiMap, id_mysql >::wifi_vec_traits::
  select (key_type& k, value_type& v, void* d)
  {
    using namespace mysql;
    using mysql::select_statement;

    statements_type& sts (*static_cast< statements_type* > (d));
    data_image_type& di (sts.data_image ());

    init (k, v, di, &sts.connection ().database ());

    select_statement& st (sts.select_statement ());
    select_statement::result r (st.fetch ());

    if (r == select_statement::truncated)
    {
      grow (di, sts.select_image_truncated ());

      if (sts.data_binding_test_version ())
      {
        bind (sts.data_bind (), 0, sts.id_binding ().count, di);
        sts.data_binding_update_version ();
        st.refetch ();
      }
    }

    return r != select_statement::no_data;
  }

  void access::object_traits_impl< ::WifiMap, id_mysql >::wifi_vec_traits::
  delete_ (void* d)
  {
    using namespace mysql;

    statements_type& sts (*static_cast< statements_type* > (d));
    sts.delete_statement ().execute ();
  }

  void access::object_traits_impl< ::WifiMap, id_mysql >::wifi_vec_traits::
  persist (const container_type& c,
           statements_type& sts)
  {
    using namespace mysql;

    functions_type& fs (sts.functions ());
    container_traits_type::persist (c, fs);
  }

  void access::object_traits_impl< ::WifiMap, id_mysql >::wifi_vec_traits::
  load (container_type& c,
        statements_type& sts)
  {
    using namespace mysql;
    using mysql::select_statement;

    const binding& id (sts.id_binding ());

    if (sts.data_binding_test_version ())
    {
      bind (sts.data_bind (), id.bind, id.count, sts.data_image ());
      sts.data_binding_update_version ();
    }

    select_statement& st (sts.select_statement ());
    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    if (r == select_statement::truncated)
    {
      data_image_type& di (sts.data_image ());
      grow (di, sts.select_image_truncated ());

      if (sts.data_binding_test_version ())
      {
        bind (sts.data_bind (), 0, id.count, di);
        sts.data_binding_update_version ();
        st.refetch ();
      }
    }

    bool more (r != select_statement::no_data);

    functions_type& fs (sts.functions ());
    container_traits_type::load (c, more, fs);
  }

  void access::object_traits_impl< ::WifiMap, id_mysql >::wifi_vec_traits::
  update (const container_type& c,
          statements_type& sts)
  {
    using namespace mysql;

    functions_type& fs (sts.functions ());
    container_traits_type::update (c, fs);
  }

  void access::object_traits_impl< ::WifiMap, id_mysql >::wifi_vec_traits::
  erase (statements_type& sts)
  {
    using namespace mysql;

    functions_type& fs (sts.functions ());
    container_traits_type::erase (fs);
  }

  access::object_traits_impl< ::WifiMap, id_mysql >::id_type
  access::object_traits_impl< ::WifiMap, id_mysql >::
  id (const id_image_type& i)
  {
    mysql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_value (
        id,
        i.id_value,
        i.id_null);
    }

    return id;
  }

  access::object_traits_impl< ::WifiMap, id_mysql >::id_type
  access::object_traits_impl< ::WifiMap, id_mysql >::
  id (const image_type& i)
  {
    mysql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_value (
        id,
        i.id_value,
        i.id_null);
    }

    return id;
  }

  bool access::object_traits_impl< ::WifiMap, id_mysql >::
  grow (image_type& i,
        my_bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // id_
    //
    t[0UL] = 0;

    return grew;
  }

  void access::object_traits_impl< ::WifiMap, id_mysql >::
  bind (MYSQL_BIND* b,
        image_type& i,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    std::size_t n (0);

    // id_
    //
    if (sk != statement_update)
    {
      b[n].buffer_type = MYSQL_TYPE_LONGLONG;
      b[n].is_unsigned = 1;
      b[n].buffer = &i.id_value;
      b[n].is_null = &i.id_null;
      n++;
    }
  }

  void access::object_traits_impl< ::WifiMap, id_mysql >::
  bind (MYSQL_BIND* b, id_image_type& i)
  {
    std::size_t n (0);
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 1;
    b[n].buffer = &i.id_value;
    b[n].is_null = &i.id_null;
  }

  bool access::object_traits_impl< ::WifiMap, id_mysql >::
  init (image_type& i,
        const object_type& o,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    bool grew (false);

    // id_
    //
    if (sk == statement_insert)
    {
      long unsigned int const& v =
        o.id_;

      bool is_null (false);
      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_image (
        i.id_value, is_null, v);
      i.id_null = is_null;
    }

    return grew;
  }

  void access::object_traits_impl< ::WifiMap, id_mysql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // id_
    //
    {
      long unsigned int& v =
        o.id_;

      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_value (
        v,
        i.id_value,
        i.id_null);
    }
  }

  void access::object_traits_impl< ::WifiMap, id_mysql >::
  init (id_image_type& i, const id_type& id)
  {
    {
      bool is_null (false);
      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_image (
        i.id_value, is_null, id);
      i.id_null = is_null;
    }
  }

  const char access::object_traits_impl< ::WifiMap, id_mysql >::persist_statement[] =
  "INSERT INTO `WifiMap` "
  "(`id`) "
  "VALUES "
  "(?)";

  const char access::object_traits_impl< ::WifiMap, id_mysql >::find_statement[] =
  "SELECT "
  "`WifiMap`.`id` "
  "FROM `WifiMap` "
  "WHERE `WifiMap`.`id`=?";

  const char access::object_traits_impl< ::WifiMap, id_mysql >::erase_statement[] =
  "DELETE FROM `WifiMap` "
  "WHERE `id`=?";

  const char access::object_traits_impl< ::WifiMap, id_mysql >::query_statement[] =
  "SELECT "
  "`WifiMap`.`id` "
  "FROM `WifiMap`";

  const char access::object_traits_impl< ::WifiMap, id_mysql >::erase_query_statement[] =
  "DELETE FROM `WifiMap`";

  const char access::object_traits_impl< ::WifiMap, id_mysql >::table_name[] =
  "`WifiMap`";

  void access::object_traits_impl< ::WifiMap, id_mysql >::
  persist (database& db, object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    if (init (im, obj, statement_insert))
      im.version++;

    im.id_value = 0;

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    {
      id_image_type& i (sts.id_image ());
      binding& b (sts.id_image_binding ());
      if (i.version != sts.id_image_version () || b.version == 0)
      {
        bind (b.bind, i);
        sts.id_image_version (i.version);
        b.version++;
      }
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    obj.id_ = id (sts.id_image ());

    id_image_type& i (sts.id_image ());
    init (i, obj.id_);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    extra_statement_cache_type& esc (sts.extra_statement_cache ());

    // wifi_vec_
    //
    {
      ::std::map< ::std::basic_string< char >, int > const& v =
        obj.wifi_vec_;

      wifi_vec_traits::persist (
        v,
        esc.wifi_vec_);
    }

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::post_persist);
  }

  void access::object_traits_impl< ::WifiMap, id_mysql >::
  update (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace mysql;
    using mysql::update_statement;

    callback (db, obj, callback_event::pre_update);

    mysql::transaction& tr (mysql::transaction::current ());
    mysql::connection& conn (tr.connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    {
      id_image_type& i (sts.id_image ());
      init (i, obj.id_);

      binding& idb (sts.id_image_binding ());
      if (i.version != sts.id_image_version () || idb.version == 0)
      {
        bind (idb.bind, i);
        sts.id_image_version (i.version);
        idb.version++;
      }
    }

    extra_statement_cache_type& esc (sts.extra_statement_cache ());

    // wifi_vec_
    //
    {
      ::std::map< ::std::basic_string< char >, int > const& v =
        obj.wifi_vec_;

      wifi_vec_traits::update (
        v,
        esc.wifi_vec_);
    }

    callback (db, obj, callback_event::post_update);
    pointer_cache_traits::update (db, obj);
  }

  void access::object_traits_impl< ::WifiMap, id_mysql >::
  erase (database& db, const id_type& id)
  {
    using namespace mysql;

    ODB_POTENTIALLY_UNUSED (db);

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    extra_statement_cache_type& esc (sts.extra_statement_cache ());

    // wifi_vec_
    //
    wifi_vec_traits::erase (
      esc.wifi_vec_);

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    pointer_cache_traits::erase (db, id);
  }

  access::object_traits_impl< ::WifiMap, id_mysql >::pointer_type
  access::object_traits_impl< ::WifiMap, id_mysql >::
  find (database& db, const id_type& id)
  {
    using namespace mysql;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();
    }

    pointer_type p (
      access::object_factory<object_type, pointer_type>::create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
      ODB_POTENTIALLY_UNUSED (st);

      callback (db, obj, callback_event::pre_load);
      init (obj, sts.image (), &db);
      load_ (sts, obj, false);
      sts.load_delayed (0);
      l.unlock ();
      callback (db, obj, callback_event::post_load);
      pointer_cache_traits::load (ig.position ());
    }
    else
      sts.delay_load (id, obj, ig.position ());

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::WifiMap, id_mysql >::
  find (database& db, const id_type& id, object_type& obj)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, false);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::WifiMap, id_mysql >::
  reload (database& db, object_type& obj)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    const id_type& id  (
      obj.id_);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, true);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::WifiMap, id_mysql >::
  find_ (statements_type& sts,
         const id_type* id)
  {
    using namespace mysql;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    return r != select_statement::no_data;
  }

  void access::object_traits_impl< ::WifiMap, id_mysql >::
  load_ (statements_type& sts,
         object_type& obj,
         bool reload)
  {
    ODB_POTENTIALLY_UNUSED (reload);

    extra_statement_cache_type& esc (sts.extra_statement_cache ());

    // wifi_vec_
    //
    {
      ::std::map< ::std::basic_string< char >, int >& v =
        obj.wifi_vec_;

      wifi_vec_traits::load (
        v,
        esc.wifi_vec_);
    }
  }

  result< access::object_traits_impl< ::WifiMap, id_mysql >::object_type >
  access::object_traits_impl< ::WifiMap, id_mysql >::
  query (database&, const query_base_type& q)
  {
    using namespace mysql;
    using odb::details::shared;
    using odb::details::shared_ptr;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += " ";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        conn,
        text,
        false,
        true,
        q.parameters_binding (),
        imb));

    st->execute ();

    shared_ptr< odb::object_result_impl<object_type> > r (
      new (shared) mysql::object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::WifiMap, id_mysql >::
  erase_query (database&, const query_base_type& q)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());

    std::string text (erase_query_statement);
    if (!q.empty ())
    {
      text += ' ';
      text += q.clause ();
    }

    q.init_parameters ();
    delete_statement st (
      conn,
      text,
      q.parameters_binding ());

    return st.execute ();
  }
}

#include <odb/post.hxx>