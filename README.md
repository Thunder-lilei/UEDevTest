# UEDevTest

UE 5.8 工具开发学习项目兼作品集：以编辑器工具为核心（后续包含客户端相关开发），每个工具以独立插件形式挂在 `Plugins/` 下。

**当前工具：Asset Audit（资产审计系统）** —— 用 Asset Registry 元数据扫描项目资产，按可配置规则（命名规范 / 孤儿资产 / 贴图规格 / 重定向器残留）产出 JSON/CSV/HTML 审计报告；C++ 编辑器插件 + Python 脚本双轨，支持编辑器面板与 Commandlet 无头 CI 两种运行方式。

## 仓库结构

```
Docs/                开发文档（架构设计 / 目录结构 / 阶段任务清单）
Plugins/AssetAudit/  资产审计插件（Editor-only）
Source/              工程默认模块
scripts/             无头审计脚本（CI 用）
```

详细文档见 [Docs/README.md](Docs/README.md) 与 [Docs/开发任务清单.md](Docs/开发任务清单.md)。

## 环境

- Unreal Engine 5.8
- Visual Studio 2022+（含 C++ 工作负载）
- Git LFS（管理 .uasset / .umap 等二进制资产）
