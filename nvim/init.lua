-- Load Lazy plugin manager
local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not vim.loop.fs_stat(lazypath) then
  vim.fn.system({
      "git",
      "clone",
      "--filter=blob:none",
      "https://github.com/folke/lazy.nvim.git",
      "--branch=stable",
      lazypath,
  })
end
vim.opt.rtp:prepend(lazypath)

vim.opt.clipboard = "unnamedplus"
vim.wo.number = true
vim.wo.relativenumber = true

vim.opt.tabstop = 8
vim.opt.softtabstop = 4
vim.opt.shiftwidth = 4

require("lazy").setup({
    {
      "catppuccin/nvim",
      name = "catppuccin",
      priority = 1000,
      config = function()
        require("catppuccin").setup({
          flavour = "mocha", -- latte, frappe, macchiato, mocha
          transparent_background = false,
        })
        vim.cmd.colorscheme "catppuccin"
      end,
    },
    {
      "folke/snacks.nvim",
      ---@type snacks.Config
      opts = {
        indent = {
            -- config
        },
      },
    },
    {
	'nvimdev/dashboard-nvim',
	event = 'VimEnter',
	config = function()
	require('dashboard').setup {
	    theme = 'doom',
	    config = {
	    header = {
	      [[                                                                   ]],
	      [[      ████ ██████           █████      ██                    ]],
	      [[     ███████████             █████                            ]],
	      [[     █████████ ███████████████████ ███   ███████████  ]],
	      [[    █████████  ███    █████████████ █████ ██████████████  ]],
	      [[   █████████ ██████████ █████████ █████ █████ ████ █████  ]],
	      [[ ███████████ ███    ███ █████████ █████ █████ ████ █████ ]],
	      [[██████  █████████████████████ ████ █████ █████ ████ ██████]],
	      [[ ]],
	    },
	    center = {
	        {
	          icon = "  ",
	          desc = "New File",
	          action = "ene | startinsert",
	          key = "n",
	        },
	        {
	          icon = "󰒲  ",
	          desc = "Lazy",
	          action = "Lazy",
	          key = "l",
	        },
	        {
	          icon = "  ",
	          desc = "Quit",
	          action = "qa",
	          key = "q",
	        },
	      },
	      footer = {
	        "Neovim loaded successfully",
	      },
	    },
	}
	  end,
    },
    { -- telescope 
      'nvim-telescope/telescope.nvim', tag = '0.1.8',
      dependencies = {
          'nvim-lua/plenary.nvim',
          { 'nvim-telescope/telescope-fzf-native.nvim', build = 'make' },
      }
    },
    {
       'nvim-lualine/lualine.nvim',
       dependencies = { 'nvim-tree/nvim-web-devicons' }
    }
})

local builtin = require("telescope.builtin")
vim.keymap.set('n', '<C-p>', builtin.find_files, {})
require('lualine').setup()
