# include	<stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# include	<mach/vm_statistics.h>
# include	<mach/mach_types.h>
# include	<mach/mach_init.h>
# include	<mach/mach_host.h>

int
	GetCPULoad(
	void
) {
	int FileHandler;
	char FileBuffer[1024];
	float load;

	FileHandler = open("/proc/loadavg", O_RDONLY);
	if(FileHandler < 0) {
		return -1; }
	read(FileHandler, FileBuffer, sizeof(FileBuffer) - 1);
	sscanf(FileBuffer, "%f", &load);
	close(FileHandler);
	return (int)(load * 100);
}

int
	main(
	int         _arc,
	const char* _arv[]
) {
	printf("CPU Load : %d\n", GetCPULoad());
	// vm_size_t				page_size;
	// mach_port_t				mach_port;
	// mach_msg_type_number_t	count;
	// vm_statistics64_data_t	vm_stats;

	// mach_port = mach_host_self(); // Returns the host self port
	// 	printf("%d\n", mach_port);
	
	// count = sizeof(vm_stats) / sizeof(natural_t);
	// 	printf("%d\n", count);

	// if (KERN_SUCCESS == host_page_size(
	// 		mach_port,
	// 		&page_size) &&
	// 	KERN_SUCCESS == host_statistics64(
	// 		mach_port,
	// 		HOST_VM_INFO,
	// 		(host_info64_t)&vm_stats,
	// 		&count))
	// {
	// 	long long free_memory = (int64_t)vm_stats.free_count * (int64_t)page_size;
	// 	long long used_memory = ((int64_t)vm_stats.active_count +
	// 							(int64_t)vm_stats.inactive_count +
	// 							(int64_t)vm_stats.wire_count) * (int64_t)page_size;
	// 	printf("free memory: %lld\nused memory: %lld\n", free_memory, used_memory);
	// }
	

	return	(0);



	
}