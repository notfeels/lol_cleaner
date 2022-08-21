#include "inc.hh"

void files::remove( std::filesystem::path path_log )
{
	std::error_code ec;
	auto removed = std::filesystem::remove_all( path_log, ec );

	if( !ec )
	{
		if( removed )
			std::cout	<< "	[+] " << path_log << " removed.\n";	
	}
	else
	{
		std::cout	<< "	[!] " << path_log << " failed to remove.\n";	
	}
		
}

void files::clear_logs( )
{
	std::cout << "[-] Deleting logs...\n";

	std::filesystem::path league_folders[ ] = {
		"C:\\ProgramData\\Riot Games",
		"C:\\ProgramData\\Riot Games\\machine.cfg",
		"C:\\Riot Games\\League of Legends\\Config",
		"C:\\Riot Games\\League of Legends\\Logs",
		"C:\\Riot Games\\League of Legends\\debug.log",
		"C:\\Riot Games\\Riot Client\\UX\\natives_blob.bin",
		"C:\\Riot Games\\Riot Client\\UX\\snapshot_blob.bin",
		"C:\\Riot Games\\Riot Client\\UX\\v8_context_snapshot.bin",
		"C:\\Riot Games\\Riot Client\\UX\\icudtl.dat",
		"",
	};

	auto appdata = std::filesystem::temp_directory_path( ).parent_path( ).parent_path( );
	appdata /= "Riot Games";
	league_folders[ 9 ] += appdata;

	for( int i = 0; i < ARRAYSIZE( league_folders ); i++ )
		files::remove( league_folders [ i ] );

	std::cout << "\n";
}