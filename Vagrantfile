    VAGRANTFILE_API_VERSION = "2"

    MANIFEST = "default.pp"
    MANIFESTS_PATH = "Provision/Puppet/manifests"
    CUSTOM_MODULES_PATH = "Provision/Puppet/modules"
    LIBRARIAN_MODULES_PATH = "Provision/Puppet/librarian/modules"

    Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|

        # Virtualbox environment
        config.vm.define :poco_sample_hosting do |sh|

            sh.vm.boot_timeout = 900
            sh.vm.box = "ubuntu/trusty32"
            sh.vm.hostname = "poco-sample-hosting"
            sh.vm.network :private_network, ip: "192.168.1.101"

            sh.ssh.forward_agent = true
            sh.ssh.insert_key = false

            sh.vm.provider :virtualbox do |virtualbox|

                virtualbox.customize [
                    "modifyvm", :id,
                    "--memory", "512",
                    "--cpus", "1",
                    "--hwvirtex", "off",
                    "--pae", "on",
                    "--ioapic", "off",
                    "--natdnsproxy1", "on",
                    "--natdnshostresolver1", "on"
                ]

            end

        end

        # Provisioning directives
        config.vm.provision "shell" do |local_userdata|
            local_userdata.path = "Provision/Shell/bootloader.sh"
            local_userdata.privileged = "yes"
        end

        config.vm.provision "puppet" do |puppet|

            puppet.manifests_path = MANIFESTS_PATH
            puppet.manifest_file  = MANIFEST
            puppet.module_path = [ LIBRARIAN_MODULES_PATH, CUSTOM_MODULES_PATH ]

            puppet.facter = {
                # Specifying the LANG environment variable this way is a work around.
                "hack=hack LANG=en_US.UTF-8 hack" => "hack"
            }

        end

    end
