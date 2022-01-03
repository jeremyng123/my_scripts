@REM Use administrator cmd, and then reboot
bcdedit /set hypervisorlaunchtype off

@REM re-enable the hypervisor
bcdedit /set hypervisorlaunchtype auto