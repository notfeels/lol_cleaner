#include "inc.hh"

void files::remove( const std::filesystem::path path_log )
{
	std::error_code ec;
	const auto removed = std::filesystem::remove_all( path_log, ec );

	if( !ec )
	{
		if( removed )
			std::cout << "	[+] " << path_log << " removed.\n";	
	}
	else
	{
		std::cout << "	[!] " << path_log << " failed to remove.\n";	
	}
}

void files::clear_logs( )
{
	std::cout << "[-] Deleting logs...\n";

	std::filesystem::path paths[ ] = {
		R"(C:\ProgramData\Riot Games)",
		R"(C:\ProgramData\Riot Games\machine.cfg)",
		R"(C:\Riot Games\League of Legends\Config)",
		R"(C:\Riot Games\League of Legends\Logs)",
		R"(C:\Riot Games\League of Legends\debug.log)",
		R"(C:\Riot Games\Riot Client\UX\natives_blob.bin)",
		R"(C:\Riot Games\Riot Client\UX\snapshot_blob.bin)",
		R"(C:\Riot Games\Riot Client\UX\v8_context_snapshot.bin)",
		R"(C:\Riot Games\Riot Client\UX\icudtl.dat)",
		""
	};

	auto appdata = std::filesystem::temp_directory_path( ).parent_path( ).parent_path( );
	appdata /= "Riot Games";
	paths[ 9 ] += appdata;

	for( const auto& path : paths )
		files::remove( path );

	std::cout << "\n";
}