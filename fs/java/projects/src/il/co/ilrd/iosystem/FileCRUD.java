package il.co.ilrd.iosystem;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.Objects;

class FileCRUD implements CRUD<Integer, String> {
    private String path = null;
    private BufferedWriter bw = null;
    private BufferedReader br = null;

    public FileCRUD(String path) throws IOException {
        Objects.requireNonNull(path);
        this.path = path;
        bw = new BufferedWriter(new FileWriter(path));
        br = new BufferedReader(new FileReader(path));
    }

    @Override
    public void close() throws Exception {
        bw.close();
        br.close();
    }

    @Override
    public Integer create(String data) throws IOException {
        bw.write(data);
        bw.newLine();
        bw.flush();
        return Files.readAllLines(Paths.get(path)).size() - 1;
    }

    @Override
    public String read(Integer key) throws IOException {
        return Files.readAllLines(Paths.get(path)).get(key);
    }

    @Override
    public void update(Integer key, String data) throws IOException, ClassNotFoundException {
        List<String> list = Files.readAllLines(Paths.get(path));
        list.remove((int) key);
        BufferedWriter bw1 = new BufferedWriter(new FileWriter(path));
        bw1.close();
        for (int i = 0; i < key; ++i) {
            create(list.get(i));
        }
        create(data);
        for (int i = key; i < list.size(); ++i) {
            create(list.get(i));

        }
    }

    @Override
    public void delete(Integer key) throws IOException, ClassNotFoundException {
        List<String> list = Files.readAllLines(Paths.get(path));
        list.remove((int) key);
        BufferedWriter bw1 = new BufferedWriter(new FileWriter(path));
        bw1.close();
        for (String str : list) {
            create(str);
        }
    }

}