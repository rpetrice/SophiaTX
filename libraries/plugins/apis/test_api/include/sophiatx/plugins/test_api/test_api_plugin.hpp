#pragma once
#include <appbase/application.hpp>

#include <sophiatx/plugins/json_rpc/json_rpc_plugin.hpp>
#include <sophiatx/plugins/json_rpc/utility.hpp>

#define SOPHIATX_TEST_API_PLUGIN_NAME "test_api"

namespace sophiatx { namespace plugins { namespace test_api {

using namespace appbase;

struct test_api_a_args {};
struct test_api_b_args {};

struct test_api_a_return { std::string value; };
struct test_api_b_return { std::string value; };

class test_api_plugin : public appbase::plugin< test_api_plugin >
{
   public:
      test_api_plugin();
      virtual ~test_api_plugin();

      //APPBASE_PLUGIN_REQUIRES()
      APPBASE_PLUGIN_REQUIRES( (plugins::json_rpc::json_rpc_plugin) );

      static const std::string& name() { static std::string name = SOPHIATX_TEST_API_PLUGIN_NAME; return name; }

      static void set_program_options( options_description&, options_description& ) {}

      virtual void plugin_initialize( const variables_map& options ) override;
      virtual void plugin_startup() override;
      virtual void plugin_shutdown() override;

      DECLARE_API(
         (test_api_a)
         (test_api_b)
      )
};

} } } // sophiatx::plugins::test_api

FC_REFLECT( sophiatx::plugins::test_api::test_api_a_args, )
FC_REFLECT( sophiatx::plugins::test_api::test_api_b_args, )
FC_REFLECT( sophiatx::plugins::test_api::test_api_a_return, (value) )
FC_REFLECT( sophiatx::plugins::test_api::test_api_b_return, (value) )
