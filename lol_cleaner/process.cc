#include "inc.hh"

void process::close( std::string process_name )
{
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof( PROCESSENTRY32 );

	const auto snapshot = CreateToolhelp32Snapshot( TH32CS_SNAPALL, NULL );

	if( Process32First( snapshot, &entry ) )
	{
		while( Process32Next( snapshot, &entry ) )
		{
			if( entry.szExeFile == process_name )
			{
				const auto handle_process = OpenProcess( PROCESS_TERMINATE, FALSE, entry.th32ProcessID );
				TerminateProcess( handle_process, 9 );
				CloseHandle( handle_process );
				std::cout << "	[+] " << process_name << " closed.\n";
			}
		}
	}

	CloseHandle( snapshot );
}

void process::close_all(  )
{
	std::cout << "[-] Stopping Riot Games & League of Legends processes...\n";

	std::string league_processes[ ] = {
		"LeagueCrashHandler.exe",
		"League of Legends.exe",
		"LeagueClientUx.exe",
		"LeagueClient.exe",
		"RiotClientServices.exe"
	};

	for( int i = 0; i < ARRAYSIZE( league_processes ); i++ )
		process::close( league_processes[ i ] );

	std::cout << "\n";

	std::this_thread::sleep_for( std::chrono::seconds( 3 ) );
}