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
	 -- lazy.nvim
	{
	  "folke/snacks.nvim",
	  ---@type snacks.Config
	  opts = {
	    indent = {
	      -- your indent configuration comes here
	      -- or leave it empty to use the default settings
	      -- refer to the configuration section below
	    }
	  }
	},
  	{ -- telescope 
  	  'nvim-telescope/telescope.nvim', tag = '0.1.8',
  	  dependencies = {
  	      'nvim-lua/plenary.nvim',
  	      { 'nvim-telescope/telescope-fzf-native.nvim', build = 'make' },
  	  }
  	},-- lazy.nvim
{
    "lukas-reineke/indent-blankline.nvim",
    main = "ibl",
    ---@module "ibl"
    ---@type ibl.config
    opts = {},
},
	{
  'stevearc/conform.nvim',
  opts = {},
},
	{
	    'nvim-lualine/lualine.nvim',
	    dependencies = { 'nvim-tree/nvim-web-devicons' }
	}
})
local builtin = require("telescope.builtin")
vim.keymap.set('n', '<C-p>', builtin.find_files, {})
require('lualine').setup()
options = { theme = 'gruvbox-material' }

require("conform").setup({
  formatters_by_ft = {
    lua = { "stylua" },
    -- Conform will run multiple formatters sequentially
    python = { "isort", "black" },
    -- You can customize some of the format options for the filetype (:help conform.format)
    rust = { "rustfmt", lsp_format = "fallback" },
    -- Conform will run the first available formatter
    javascript = { "prettierd", "prettier", stop_after_first = true },
  },
})
