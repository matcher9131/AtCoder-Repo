const enumerateCppFiles = async (rootDir: string): Promise<string[]> => {
    const res: string[] = [];
    for await (const entry of Deno.readDir(rootDir)) {
        if (entry.isDirectory) {
            const childResult = await enumerateCppFiles(`${rootDir}/${entry.name}`);
            res.push(...childResult);
        } else if (entry.isFile) {
            if (entry.name.endsWith(".cpp")) {
                res.push(`${rootDir}/${entry.name}`);
            }
        }
    }
    return res;
}

const textFilter = (text: string) => async (filepath: string): Promise<boolean> => {
    const res = await fetch(new URL(filepath, import.meta.url));
    const fileText = await res.text();
    return fileText.includes(text);
};

const asyncFilter = async <T>(arr: T[], predicate: (element: T) => Promise<Boolean>): Promise<T[]> => {
    const results = await Promise.all(arr.map(predicate));
    return arr.filter((_, index) => results[index]);
}

const files = await asyncFilter(await enumerateCppFiles("."), textFilter("unordered_map<"));
for (const file of files) console.log(file);
