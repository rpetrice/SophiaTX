#pragma once
#include <sophiatx/plugins/chain/chain_plugin.hpp>
#include <sophiatx/plugins/json_rpc/json_rpc_plugin.hpp>

#include <appbase/application.hpp>

namespace sophiatx { namespace plugins { namespace block_api {

using namespace appbase;

#define SOPHIATX_BLOCK_API_PLUGIN_NAME "block_api"

class block_api_plugin : public plugin< block_api_plugin >
{
   public:
      block_api_plugin();
      virtual ~block_api_plugin();

      APPBASE_PLUGIN_REQUIRES(
         (sophiatx::plugins::json_rpc::json_rpc_plugin)
         (sophiatx::plugins::chain::chain_plugin)
      )

      static const std::string& name() { static std::string name = SOPHIATX_BLOCK_API_PLUGIN_NAME; return name; }

      static void set_program_options(
         options_description& cli,
         options_description& cfg );
      void plugin_initialize( const variables_map& options ) override;
      void plugin_startup() override;
      void plugin_shutdown() override;

      std::shared_ptr< class block_api > api;
};

} } } // sophiatx::plugins::block_api
