# fprime-rtems-poc
F´ PoC on RTEMS LEON 3 w/ Renode


> **Note** With the help of https://github.com/antmicro/renode-rtems-leon3

# Documentation

- Renode Release: https://github.com/renode/renode/releases
- Antmicro's Devide Tree Source to Renode platform file: https://github.com/antmicro/dts2repl
- Renode command line utility: https://github.com/antmicro/renode-run
- CAES's Bare-C Cross-Compiler User Manuel: https://www.gaisler.com/anonftp/bcc2/doc/bcc.pdf
- MKPROM2 Gailer utility program which converts a LEON RAM application image into a bootable ROM image https://www.gaisler.com/anonftp/mkprom2/

# Standalone test

## Renode

- Install latest Renode: `wget https://github.com/renode/renode/releases/download/v1.13.3/renode-1.13.3.linux-portable.tar.gz`

- Extract the archve `tar -xvzf renode-1.13.3.linux-portable.tar.gz`
- Edit the `.bashrc` file to declare Renode in the path:

```sh
RENODE_PATH='/home/user/renode_1.13.3_portable'
export PATH="$RENODE_PATH:$PATH"
```

## Gailer toolsuite
### bcc2

```
curl -LO 'https://www.gaisler.com/anonftp/bcc2/bin/bcc-2.2.0-gcc-linux64.tar.xz'
tar xf bcc-2.2.0-gcc-linux64.tar.xz
```

### grlib

```
curl -LO 'https://www.gaisler.com/products/grlib/grlib-gpl-2021.2-b4267.tar.gz'
tar xf grlib-gpl-2021.2-b4267.tar.gz
```

# Usage
- Launch renode and the Renode script `.resc`:

```sh
$ renode
23:20:06.9790 [WARNING] Couldn't start UI - falling back to console mode
23:20:07.4251 [INFO] Loaded monitor commands from: /home/musubi/renode_1.13.3_portable/scripts/monitor.py
Renode, version 1.13.3.19119 (a72a1fa1-202302201037)

(monitor) s @leon3_rtems.resc
23:20:18.0047 [INFO] Including script: /home/musubi/codelab/fprime-rtems-poc/swil/leon3_rtems.resc
23:20:18.0449 [INFO] System bus created.
23:20:18.5710 [INFO] Setting Entry Point value to 0x0
Current 'PATH' value is: /home/musubi/renode_1.13.3_portable;/home/musubi/codelab/fprime-rtems-poc/swil;/home/musubi/codelab/fprime-rtems-poc/swil
23:20:18.7936 [INFO] sysbus: Loading segment of 259520 bytes length at 0x40000000.
23:20:18.7987 [INFO] sysbus: Loading segment of 26736 bytes length at 0x4003F5C0.
23:20:18.8620 [INFO] cpu: Setting PC value to 0x40000000.
23:20:18.8625 [INFO] cpu: Using PC value as Entry Point value : 0x40000000
23:20:19.0590 [INFO] Leon3: Machine started.
23:20:19.1161 [WARNING] mic: Unhandled read from offset 0x20.
23:20:19.1339 [INFO] uart: [host: 0.51s (+0.51s)|virt: 1.2ms (+1.2ms)] Hello World
```

> Warning: the Telnet mode does not work...

```sh
$ renode --port 1234
23:36:23.1845 [WARNING] Couldn't start UI - falling back to console mode
23:36:23.6367 [INFO] Loaded monitor commands from: /home/musubi/renode_1.13.3_portable/scripts/monitor.py
Renode, version 1.13.3.19119 (a72a1fa1-202302201037)
```

And we could not access the terminal throuh Telnet:
```sh
$ telnet 127.0.0.1 1234
Trying 127.0.0.1...
telnet: Unable to connect to remote host: Connection refused
```